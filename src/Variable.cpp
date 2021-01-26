#include "Variable.h"

Variable::Variable()
{
    //ctor
}
void Variable::parse(queue<Token>& tokens) {
    if(tokens.empty())
        mad("Missing variable");

    Token token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Incorrect variable identifier");

    name = token.word;
    tokens.pop();
}

string Variable::translate() {
    return name;
}
