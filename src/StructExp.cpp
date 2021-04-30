#include "StructExp.h"

StructExp::StructExp()
{
    //ctor
}
void StructExp::parse(Expression _exp, deque<Token>& tokens) {
    if(tokens.empty())
        mad("Missing variable");
    exp = _exp;

    Token token = tokens.front();

    if(token.type != "DOT")
        mad("Missing '.'");

    tokens.pop_front();

    token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Missing struct variable reference");

    varName = token.word;
    tokens.pop_front();
}

string StructExp::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    return exp.translate(fun_name, tabs, funCallNumber, previousCode) + "." + varName;
}

void StructExp::changeVariablesName(string prefix) {
    varName = prefix + "_" + varName;
    exp.changeVariablesName(prefix);
}
