#include "Variable.h"

Variable::Variable()
{
    //ctor
}
void Variable::parse(deque<Token>& tokens) {
    if(tokens.empty())
        mad("Missing variable");

    Token token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Incorrect variable identifier");

    name = token.word;
    tokens.pop_front();
}

string Variable::translate() {
    return name;
}

void Variable::changeName(string prefix) {
    name = prefix + "_" + name;
}
