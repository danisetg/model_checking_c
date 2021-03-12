#include "IntDecl.h"

IntDecl::IntDecl()
{
    //ctor
}

void IntDecl::parse(deque<Token>& tokens) {

    Token token = tokens.front();

    if(token.type != "INT_KEYWORD")
        mad("Not an int");

    tokens.pop_front();

    token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Missing identifier");

    name = token.word;

    tokens.pop_front();
}

string IntDecl::translate() {
    return "int " + name;
}
