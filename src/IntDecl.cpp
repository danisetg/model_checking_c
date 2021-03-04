#include "IntDecl.h"

IntDecl::IntDecl()
{
    //ctor
}

void IntDecl::parse(queue<Token>& tokens) {

    Token token = tokens.front();

    if(token.type != "INT_KEYWORD")
        mad("Not an int");

    tokens.pop();

    token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Missing identifier");

    name = token.word;

    tokens.pop();
}

string IntDecl::translate() {
    return "int " + name;
}
