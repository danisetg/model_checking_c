#include "DFSpecificationGenerator.h"

DFSpecificationGenerator::DFSpecificationGenerator()
{
}
DFSpecificationGenerator::DFSpecificationGenerator(const Program &_p)
{
    p = Program(_p);
}

void DFSpecificationGenerator::modifyProgram() {
    int statementNumber = 1;
    numVariables = 0;
    vector<string> filling;
    defs.push_back(filling);
    uses.push_back(filling);
    variables.push_back("");
    for(int i = 0; i < p.f.size(); i++) {
       for(int h = 0; h < p.f[i].statements.size(); h++) {
           addLabels(p.f[i].statements[h], statementNumber, p.f[i].name);
       }
    }
    Define endDefine;
    endDefine.name = "final";
    endDefine.exp.type = VARIABLE;
    endDefine.exp.variable = new Variable();
    endDefine.exp.variable->name = "main@end";
    p.def.push_back(endDefine);
}

vector<string> DFSpecificationGenerator::getLabels(Expression exp, int statementNumber, bool def) {
    vector<string> labels;
    vector<string> aux;
    switch(exp.type) {
        case UNARY_OPERATOR:
            labels = getLabels(exp.unaryOperator->expression, statementNumber, false);
            break;
        case BINARY_OPERATOR:
            labels = getLabels(exp.binaryOperator->exp1, statementNumber, false);
            aux = getLabels(exp.binaryOperator->exp2, statementNumber, false);
            labels.insert(labels.begin(), aux.begin(), aux.end());
            break;
        case ASSIGNMENT:
            labels = getLabels(exp.assignment->leftSide, statementNumber, true);
            aux = getLabels(exp.assignment->exp, statementNumber, false);
            labels.insert(labels.begin(), aux.begin(), aux.end());
            break;
        case VARIABLE:
            if(!variableIndex[exp.variable->name]) {
                variableIndex[exp.variable->name] = ++numVariables;
                variables.push_back(exp.variable->name);
                vector<string> tmp;
                defs.push_back(tmp);
                uses.push_back(tmp);
            }
            if(def) {
                string label = "d_" + exp.variable->name + "_v" + to_string(statementNumber);
                if(!labelExists[label]) {
                    labels.push_back(label);
                    defs[variableIndex[exp.variable->name]].push_back(label);
                    labelExists[label] = true;
                }
            } else{
                string label = "u_" + exp.variable->name + "_v" + to_string(statementNumber);
                if(!labelExists[label]) {
                    labels.push_back(label);
                    uses[variableIndex[exp.variable->name]].push_back(label);
                    labelExists[label] = true;
                }
            }
            break;
        case CONDITIONAL:
            labels = getLabels(exp.cond->condition, statementNumber, false);
            aux = getLabels(exp.cond->trueAssign, statementNumber, false);
            labels.insert(labels.begin(), aux.begin(), aux.end());
            aux = getLabels(exp.cond->falseAssign, statementNumber, false);
            labels.insert(labels.begin(), aux.begin(), aux.end());
            break;
        case FUN_CALL:
            for(int i = 0; i < exp.funCall->arguments.size(); i++) {
                aux = getLabels(exp.funCall->arguments[i], statementNumber, false);
                labels.insert(labels.begin(), aux.begin(), aux.end());
            }
            break;
        case ARRAY:
            for(int i = 0; i < exp.arr->positions.size(); i++) {
                aux = getLabels(exp.arr->positions[i], statementNumber, false);
                labels.insert(labels.begin(), aux.begin(), aux.end());
            }
            break;
        case INCREMENT:
            labels.push_back("u_" + exp.increment->var.name + "_v" + to_string(statementNumber));
            break;
        case DECREMENT:
            labels.push_back("u_" + exp.decrement->var.name + "_v" + to_string(statementNumber));
            break;
    }
    return labels;
}
vector<string> DFSpecificationGenerator::getVariablesLabels(vector<string> _variables, int statementNumber, bool def) {
    vector<string> labels;
    for(int i = 0; i < _variables.size(); i++) {
        if(!variableIndex[_variables[i]]) {
                variableIndex[_variables[i]] = ++numVariables;
                variables.push_back(_variables[i]);
                vector<string> tmp;
                defs.push_back(tmp);
                uses.push_back(tmp);
        }
        if(def) {
                string label = "d_" + _variables[i] + "_v" + to_string(statementNumber);
                if(!labelExists[label]) {
                    labels.push_back(label);
                    defs[variableIndex[_variables[i]]].push_back(label);
                    labelExists[label] = true;
                }

        } else{
                string label = "u_" + _variables[i] + "_v" + to_string(statementNumber);
                if(!labelExists[label]) {
                    labels.push_back(label);
                    uses[variableIndex[_variables[i]]].push_back(label);
                    labelExists[label] = true;
                }
        }
    }
    return labels;
}

void DFSpecificationGenerator::getVectorStatements(vector<Statement> &statements, int &statementNumber, string fun_name) {
     for(int i = 0; i < statements.size(); i++) {
        addLabels(statements[i], statementNumber, fun_name);
    }
}

void DFSpecificationGenerator::addDefine(string label, string fun_name) {
    Define d;
    d.name = fun_name + "_" + label;
    d.exp.type = VARIABLE;
    d.exp.variable = new Variable();
    d.exp.variable->name = fun_name + "@" + label;
    p.def.push_back(d);
}

void DFSpecificationGenerator::addLabels(Statement &st, int &statementNumber, string fun_name) {
    statementNumber++;
    vector<string> labels;
    switch(st.type) {
        case RETURN:
            labels = getLabels(st.ret->expression, statementNumber, false);
            break;
        case EXPRESSION:
            labels = getLabels(*st.expression, statementNumber, false);
            break;
        case IF:
            labels = getLabels(st.ifStatement->condition, statementNumber, false);
            getVectorStatements(st.ifStatement->ifBody, statementNumber, fun_name);
            getVectorStatements(st.ifStatement->elseBody, statementNumber, fun_name);
            break;
        case WHILE:
            labels = getLabels(st.whileStatement->endCondition, statementNumber, false);
            getVectorStatements(st.whileStatement->whileBody, statementNumber, fun_name);
            break;
        case  DO_WHILE:
            labels = getLabels(st.doWhileStatement->endCondition, statementNumber, false);
            getVectorStatements(st.doWhileStatement->body, statementNumber, fun_name);
            break;
        case PRINT:

            labels = getVariablesLabels(st.print->variables, statementNumber, false);
            break;
        case SCAN:
            labels = getVariablesLabels(st.scan->variables, statementNumber, true);
            break;
        case LABELED_STATEMENT:
            addLabels(st.labeledStatement->statement, statementNumber, fun_name);
            break;
    }


    for(int i = 0; i < labels.size(); i++) {
        addDefine(labels[i], fun_name);
        Statement tmp = Statement(st);
        st.type = LABELED_STATEMENT;
        st.labeledStatement = new LabeledStatement();
        st.labeledStatement->labelName = labels[i];
        st.labeledStatement->statement = Statement(tmp);
    }
}

vector<string> DFSpecificationGenerator::generateAllDefsSpecifications() {
    vector<string> specifications;
    ofstream outfile;
    outfile.open("all_defs.txt");
    for(int i = 1; i < defs.size(); i++) {
        if(!defs[i].size() || !uses[i].size())
            continue;

        string defi = "main_" + defs[i][0];

        for(int h = 1; h < defs[i].size(); h++)
            defi += " || main_" + defs[i][h];

        for(int h = 0; h < defs[i].size(); h++) {
            string sp = "![]!(<>main_" + defs[i][h];
            sp += " && X(!(" + defi + ") U ((main_" + uses[i][0];


            for(int k = 1; k < uses[i].size(); k++) {
                sp += " || main_" + uses[i][k];
            }
            sp += ") && <>final)))";
            specifications.push_back(sp);

            string aux = replaceAll(sp, "!", "\\neg ");
            aux = replaceAll(aux, "[]", "\\square ");
            aux = replaceAll(aux, "<>", "\\lozenge ");
            aux = replaceAll(aux, "||", "\\lor ");
            aux = replaceAll(aux, "&&", "\\land ");
            aux = replaceAll(aux, "main_", "");
            aux = replaceAll(aux, "X", "\\bigcirc ");

            outfile<<aux;
            outfile<<"\n";
        }
    }
    outfile.close();
    return specifications;
}

vector<string> DFSpecificationGenerator::generateAllUsesSpecifications() {
    vector<string> specifications;
     ofstream outfile;
    outfile.open("all_uses.txt");
    for(int i = 1; i < defs.size(); i++) {
        if(!defs[i].size() || !uses[i].size())
            continue;

        string defi = "main_" + defs[i][0];

        for(int h = 1; h < defs[i].size(); h++)
            defi += " || main_" + defs[i][h];

        for(int h = 0; h < defs[i].size(); h++) {

            for(int k = 1; k < uses[i].size(); k++) {
                string sp = "![]!(<>main_" + defs[i][h];
                sp += " && X(!(" + defi + ") U ";
                sp += "(main_" + uses[i][k] + " && <>final)))";
                specifications.push_back(sp);
                 string aux = replaceAll(sp, "!", "\\neg ");
            aux = replaceAll(aux, "[]", "\\square ");
            aux = replaceAll(aux, "<>", "\\lozenge ");
            aux = replaceAll(aux, "||", "\\lor ");
            aux = replaceAll(aux, "&&", "\\land ");
            aux = replaceAll(aux, "main_", "");
            aux = replaceAll(aux, "X", "\\bigcirc ");

            outfile<<aux;
            outfile<<"\n";
            }

        }
    }
    outfile.close();
    return specifications;
}

void DFSpecificationGenerator::generateDFSpecifications(string resultsAddr, string filename) {
    modifyProgram();
    ofstream outfile;
    outfile.open(resultsAddr + "\\" + filename + "_dft.pml");
    int tabs = 0;
    outfile<<p.translate(tabs, true);
    outfile.close();
}
