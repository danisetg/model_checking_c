#include "StructDecl.h"

StructDecl::StructDecl()
{
    //ctor
}

void StructDecl::parse(deque<Token>& tokens) {

    Token token = tokens.front();

    if(token.type != "STRUCT_KEYWORD")
        mad("Not a struct");

    tokens.pop_front();

    token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Missing struct name");


    structName = token.word;

    tokens.pop_front();

    token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Missing identifier");

    name = token.word;

    tokens.pop_front();
}

string StructDecl::translate(bool isPointer) {
    if(!isPointer)
        return structName + " " + name;

    return "int " + name;
}
