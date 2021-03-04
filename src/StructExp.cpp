#include "StructExp.h"

StructExp::StructExp()
{
    //ctor
}
void StructExp::parse(string _name, queue<Token>& tokens) {
    if(tokens.empty())
        mad("Missing variable");
    name = _name;

    Token token = tokens.front();

    if(token.type != "DOT")
        mad("Missing '.'");

    tokens.pop();

    token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Missing struct variable reference");

    varName = token.word;
    tokens.pop();
}

string StructExp::translate() {
    return name + "." + varName;
}
