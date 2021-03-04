#include "StructDecl.h"

StructDecl::StructDecl()
{
    //ctor
}

void StructDecl::parse(queue<Token>& tokens) {

    Token token = tokens.front();

    if(token.type != "STRUCT_KEYWORD")
        mad("Not a struct");

    tokens.pop();

    token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Missing struct name");


    structName = token.word;

    tokens.pop();

    token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Missing identifier");

    name = token.word;

    tokens.pop();
}

string StructDecl::translate() {
    return structName + " " + name;
}
