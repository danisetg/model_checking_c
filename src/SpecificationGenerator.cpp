#include "SpecificationGenerator.h"

SpecificationGenerator::SpecificationGenerator()
{
    //ctor
}

SpecificationGenerator::SpecificationGenerator(const Program &_p)
{
    p = Program(_p);
}

void SpecificationGenerator::changeDeclarationsToGlobal() {
    dn = cn = 1;
    for(int i = 0; i < p.f.size(); i++) {
        p.f[i].chanDeclared.clear();

        for(int h = 0; h < p.f[i].statements.size(); h++) {
            Statement st = p.f[i].statements[h];
            if(st.type == DECLARATION) {
                Declaration decl = *st.decl;
                //decl.name = p.f[i].name + "_" + decl.name;
                p.d.push_back(decl);
            }

        }
        while(true) {
            if(p.f[i].statements[0].type == DECLARATION) {
                p.f[i].statements.erase(p.f[i].statements.begin());
            } else
                break;
        }
    }
    //p.changeLocalVariablesName();
    for(int i = 0; i < p.f.size(); i++) {
        for(int h = 0; h < p.f[i].statements.size(); h++) {
            checkForIfs(p.f[i].name, p.f[i].statements[h]);
        }
    }
    Define endDefine;
    endDefine.name = "final";
    endDefine.exp.type = VARIABLE;
    endDefine.exp.variable = new Variable();
    endDefine.exp.variable->name = "main@end";
    p.def.push_back(endDefine);
}

Define SpecificationGenerator::parseIfToDefines(string fun_name, Expression exp) {
    if(exp.type == BINARY_OPERATOR && (exp.binaryOperator->op == "&&" || exp.binaryOperator->op == "||")) {
        Define def1 = parseIfToDefines(fun_name, exp.binaryOperator->exp1);
        Define def2 = parseIfToDefines(fun_name, exp.binaryOperator->exp2);

        Expression exp1;
        if(def1.name.length()) {
            exp1.type = VARIABLE;
            exp1.variable = new Variable();
            exp1.variable->name = def1.name;
        } else
            exp1 = def1.exp;

        Expression exp2;
        if(def2.name.length()) {
            exp2.type = VARIABLE;
            exp2.variable = new Variable();
            exp2.variable->name = def2.name;
        } else
            exp2 = def2.exp;

        Define d;
        d.exp.type = BINARY_OPERATOR;
        d.exp.binaryOperator = new BinaryOperator(exp.binaryOperator->op, exp1, exp2);
        d.ifLabel = "if" + to_string(dn);
        d.dn = dn;
        return d;
    } else {
        Define d;
       // d.name = fun_name + "_condition_" + to_string(dn) + to_string(cn);
        d.name = "c_" + to_string(dn) + to_string(cn);
        cn++;
        d.exp = exp;
        d.ifLabel = "if" + to_string(dn);
        d.dn = dn;
        p.def.push_back(d);
        return d;
    }
}

void SpecificationGenerator::checkForIfs(string fun_name, Statement &st) {
    vector<Statement> statements;
    Define d;
    LabeledStatement labelStatement;
    Define ifDefine;
    switch(st.type) {
        case IF:
            d = parseIfToDefines(fun_name, st.ifStatement->condition);
            //d.name = fun_name + "_decision_" + to_string(dn);
            if(d.name.length()) {
                d.exp.type = VARIABLE;
                d.exp.variable = new Variable();
                d.exp.variable->name = d.name;
            }

            d.name = "d_" + to_string(dn);


            st.ifStatement->dn = dn;

            p.def.push_back(d);

            dn++;
            cn = 1;

            for(int i = 0; i < st.ifStatement->ifBody.size();i++) {
                checkForIfs(fun_name, st.ifStatement->ifBody[i]);
            }

            for(int i = 0; i < st.ifStatement->elseBody.size();i++) {
                checkForIfs(fun_name, st.ifStatement->elseBody[i]);
            }

            ifDefine.name = "if" + to_string(st.ifStatement->dn);
            ifDefine.exp.type = VARIABLE;
            ifDefine.exp.variable = new Variable();
            ifDefine.exp.variable->name = "main@if_" + to_string(st.ifStatement->dn);

            p.def.push_back(ifDefine);

            labelStatement.labelName = "if_" + to_string(st.ifStatement->dn);
            labelStatement.statement = Statement(st);
            st.type = LABELED_STATEMENT;
            st.labeledStatement = new LabeledStatement(labelStatement);






            break;
        case WHILE:
            statements = st.whileStatement->whileBody;
            break;
        case FOR:
            statements = st.forStatement->forBody;
            break;
        case DO_WHILE:
            statements = st.doWhileStatement->body;
            break;
    }
    for(int i = 0; i < statements.size(); i++) {
        checkForIfs(fun_name, statements[i]);
    }

}

vector<string> SpecificationGenerator::generateCCSpecifications() {
    vector<string> specifications;
    for(int i = 0; i < p.def.size(); i++) {
        string name = p.def[i].name;
        string ifLabel = p.def[i].ifLabel;
        if (name.find("c_") != std::string::npos) {
            string sp1 = "![]!(" +  name  + " && " + ifLabel + " && <>final)";
            string sp2 = "![]!(!" +  name  + " && " + ifLabel + " && <>final)";
            specifications.push_back(sp1);
            specifications.push_back(sp2);
        }
    }
    return specifications;
}

vector<string> SpecificationGenerator::generateDCSpecifications() {
    vector<string> specifications;
    for(int i = 0; i < p.def.size(); i++) {
        string name = p.def[i].name;
        string ifLabel = p.def[i].ifLabel;
        if (name.find("d_") != std::string::npos) {
            string sp1 = "![]!(" +  name  + " && " + ifLabel + " && <>final)";
            string sp2 = "![]!(!" +  name  + " && " + ifLabel + " && <>final)";
            specifications.push_back(sp1);
            specifications.push_back(sp2);
        }
    }
    return specifications;
}

void SpecificationGenerator::addResetButton() {
    Declaration decl;
    decl.type = BOOL;
    decl.name = "reset";
    p.d.push_back(decl);
}

void SpecificationGenerator::translateMCDC(string resultsAddr, string filename) {
    ofstream outfile;
    outfile.open(resultsAddr + "\\" + filename + "_mcdc.pml");
    int tabs = 0;
    outfile<<p.translate(tabs, true);
    outfile.close();
}

void SpecificationGenerator::addStartLabel() {
    Statement st;
    st.type = LABELED_STATEMENT;
    st.labeledStatement = new LabeledStatement();
    st.labeledStatement->labelName = "start";
    st.labeledStatement->statement.type = PRINT;
    st.labeledStatement->statement.print = new Print();
    st.labeledStatement->statement.print->message = "Main start \"";
    p.f[p.f.size()-1].statements.insert(p.f[p.f.size()-1].statements.begin(), st);
}

void SpecificationGenerator::addInvariantsToIf(Atomic &atomic, int _dn) {
    for(int i = 0; i < p.def.size(); i++) {
        string name = p.def[i].name;
        if (name.find("c_" + to_string(_dn)) != std::string::npos) {
            Expression exp1;
            exp1.type = VARIABLE;
            exp1.variable = new Variable();
            exp1.variable->name = name + "_copy";
            Statement st;
            st.type = EXPRESSION;
            st.expression = new Expression();
            st.expression->type = ASSIGNMENT;
            st.expression->assignment = new Assignment(exp1, p.def[i].exp);
            atomic.statements.push_back(st);
        }
    }
    If ifStatement;
    Expression exp1;
    exp1.type = VARIABLE;
    exp1.variable = new Variable();
    exp1.variable->name = "reset" + to_string(_dn);

    Expression exp2;
    exp2.type = VARIABLE;
    exp2.variable = new Variable();
    exp2.variable->name = "false";

    Expression exp3;
    exp3.type = VARIABLE;
    exp3.variable = new Variable();
    exp3.variable->name = "true";

    ifStatement.condition.type = BINARY_OPERATOR;
    ifStatement.condition.binaryOperator = new BinaryOperator("==", exp1, exp2);

    Statement st;
    st.type = EXPRESSION;
    st.expression = new Expression();
    st.expression->type = ASSIGNMENT;
    st.expression->assignment = new Assignment(exp1, exp3);
    ifStatement.ifBody.push_back(st);

    Statement gotoStatement;
    gotoStatement.type = GOTO;
    gotoStatement.gto = new Goto();
    gotoStatement.gto->labelName = "start";

    ifStatement.ifBody.push_back(gotoStatement);

    Statement tmp;
    tmp.type = IF;
    tmp.ifStatement = new If();
    *tmp.ifStatement = ifStatement;

    atomic.statements.push_back(tmp);
}

void SpecificationGenerator::modifyIfs(string fun_name, Statement& st) {
    Statement aux;
    Atomic atomic;
    vector<Statement> statements;
    Declaration decl;
    switch(st.type) {
        case LABELED_STATEMENT:
            st = st.labeledStatement->statement;
            modifyIfs(fun_name, st);
            break;
        case IF:
             decl.type = BOOL;
             decl.name = "reset" + to_string(st.ifStatement->dn);
             p.d.push_back(decl);
            for(int i = 0; i < st.ifStatement->ifBody.size(); i++) {
                modifyIfs(fun_name, st.ifStatement->ifBody[i]);
            }
            for(int i = 0; i < st.ifStatement->elseBody.size(); i++) {
                modifyIfs(fun_name, st.ifStatement->elseBody[i]);
            }

            atomic.statements = st.ifStatement->ifBody;
            addInvariantsToIf(atomic, st.ifStatement->dn);
            st.ifStatement->ifBody.clear();

            aux.type = ATOMIC;
            aux.atomic = new Atomic();
            *aux.atomic = atomic;



            st.ifStatement->ifBody.push_back(aux);

            break;
        case WHILE:
            statements = st.whileStatement->whileBody;
            break;
        case FOR:
            statements = st.forStatement->forBody;
            break;
        case DO_WHILE:
            statements = st.doWhileStatement->body;
            break;
    }
    for(int i = 0; i < statements.size(); i++) {
        modifyIfs(fun_name, statements[i]);
    }

}

void SpecificationGenerator::addMCDCAuxiliaryVariables() {
    addResetButton();
    addStartLabel();
    vector<Define> auxDef;
    for(int i = 0; i < p.def.size(); i++) {
        string name = p.def[i].name;
        if (name.find("c_") != std::string::npos) {
            Declaration decl;
            decl.type = BOOL;
            decl.name = name + "_copy";
            p.d.push_back(decl);

            Expression exp1;
            exp1.type = VARIABLE;
            exp1.variable = new Variable();
            exp1.variable->name = name;

            Expression exp2;
            exp2.type = VARIABLE;
            exp2.variable = new Variable();
            exp2.variable->name = name + "_copy";

            Define def;
            def.name = "inv_" + name;
            def.exp.type = BINARY_OPERATOR;
            def.exp.binaryOperator = new BinaryOperator("==", exp1, exp2);
            auxDef.push_back(def);
        }
    }
    p.def.insert(p.def.end(), auxDef.begin(), auxDef.end());
}
void SpecificationGenerator::getConditions(Expression exp, vector<string> &conditions) {
    if(exp.type == VARIABLE)
        conditions.push_back(exp.variable->name);
    else if(exp.type == BINARY_OPERATOR) {
        getConditions(exp.binaryOperator->exp1, conditions);
        getConditions(exp.binaryOperator->exp2, conditions);
    }
}
vector<string> SpecificationGenerator::generateMCDCSpecifications(string resultsAddr, string filename) {

    vector<string> specifications;

    for(int i = 0; i < p.f.size(); i++) {
        for(int h = 0; h < p.f[i].statements.size(); h++) {

            modifyIfs(p.f[i].name, p.f[i].statements[h]);

        }
    }
    addMCDCAuxiliaryVariables();
    translateMCDC(resultsAddr, filename);
    for(int i = 0; i < p.def.size(); i++) {
        string name = p.def[i].name;
        string ifLabel = p.def[i].ifLabel;
        if (name.find("d_") != std::string::npos) {

            vector<string> conditions;
            getConditions(p.def[i].exp, conditions);

            for(int h = 0; h < conditions.size(); h++) {
                string sp = "![]!((" + name + ") && X(reset" + to_string(p.def[i].dn) + " && <>(!" + name;
                for(int k = 0; k < conditions.size(); k++) {
                    sp += " && ";
                    if(k == h)
                        sp += " !";
                    sp += "inv_" + conditions[k];
                }
                sp += ")))";
                specifications.push_back(sp);

            }
        }
    }
    return specifications;
}


void SpecificationGenerator::generateCFSpecifications(string resultsAddr, string filename) {
    changeDeclarationsToGlobal();
    ofstream outfile;
    outfile.open(resultsAddr + "\\" + filename + "_cft.pml");
    int tabs = 0;
    outfile<<p.translate(tabs, true);

    outfile.close();
}
