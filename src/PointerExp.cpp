#include "PointerExp.h"
#include "Variable.h"
PointerExp::PointerExp()
{
    //ctor
}

void PointerExp::parse(Expression _exp, deque<Token>& tokens) {
    if(tokens.empty())
        mad("Missing variable");

    exp = _exp;

    Token token = tokens.front();

    if(token.type == "ARROW") {
        tokens.pop_front();

        token = tokens.front();

        if(token.type != "IDENTIFIER")
            mad("Missing struct variable reference");

        varName = token.word;
        tokens.pop_front();
    }
}

string PointerExp::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string type;
    string code;
    switch(exp.type) {
        case VARIABLE:
            type = getPointerType(exp.variable->name);
            if(type == "-1")
                mad("Can't find pointer " + exp.variable->name);
            code = type + "_mem[" + exp.variable->name + "]";
            break;
        case POINTER_EXPRESSION:
            type = getPointerType(exp.pointerExp->varName);
            if(type == "-1")
                mad("Can't find pointer " + exp.pointerExp->varName);
            code = type + "_mem[" + exp.translate(fun_name, tabs, funCallNumber, previousCode) + "]";
            break;
    }

    if(varName.length())
        code += "." + varName;

    return code;

}

void PointerExp::changeVariablesName(string prefix) {
    varName = prefix + "_" + varName;
    exp.changeVariablesName(prefix);
}
