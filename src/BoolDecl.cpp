#include "BoolDecl.h"

BoolDecl::BoolDecl()
{
    //ctor
}

void BoolDecl::parse(deque<Token>& tokens, string name) {

    Token token = tokens.front();

    if(token.type != "BOOL_KEYWORD")
        mad("Not a bool");

    tokens.pop_front();

    token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Missing identifier");

    name = token.word;

    tokens.pop_front();
}

string BoolDecl::translate(string name) {
    return "bool " + name;
}

