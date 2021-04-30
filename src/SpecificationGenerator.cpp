#include "SpecificationGenerator.h"

SpecificationGenerator::SpecificationGenerator()
{
    //ctor
}

void SpecificationGenerator::changeDeclarationsToGlobal() {
    dn = cn = 1;
    for(int i = 0; i < p.f.size(); i++) {
        Fun f = p.f[i];
        for(int h = 0; h < f.statements.size(); h++) {
            Statement st = f.statements[h];
            if(st.type == DECLARATION) {
                Declaration decl = *st.decl;
                decl.name = f.name + "_" + decl.name;
                p.d.push_back(decl);
            } else
                checkForIfs(f.name, st);

        }
        while(true) {
            if(p.f[i].statements[0].type == DECLARATION) {
                p.f[i].statements.erase(p.f[i].statements.begin());
            } else
                break;
        }
    }
    p.changeLocalVariablesName();
}

Define SpecificationGenerator::parseIfToDefines(string fun_name, Expression exp) {
    if(exp.type == BINARY_OPERATOR && (exp.binaryOperator-> op == "&&" || exp.binaryOperator->op == "||")) {
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
        return d;
    } else {
        Define d;
        d.name = fun_name + "_c" + to_string(dn) + to_string(cn);
        cn++;
        d.exp = exp;
        p.def.push_back(d);
        return d;
    }
}

void SpecificationGenerator::checkForIfs(string fun_name, Statement st) {
    vector<Statement> statements;
    Define d;
    switch(st.type) {
        case IF:
            d = parseIfToDefines(fun_name, st.ifStatement->condition);
            d.name = fun_name + "_d" + to_string(dn);
            p.def.push_back(d);
            dn++;
            cn = 1;
            statements = st.ifStatement->ifBody;
            statements.insert(statements.begin(), st.ifStatement->elseBody.begin(), st.ifStatement->elseBody.end());
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

