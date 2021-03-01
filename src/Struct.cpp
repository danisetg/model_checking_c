#include "Struct.h"

Struct::Struct()
{
    //ctor
}

void Struct::parse(queue<Token>& tokens) {

    Token token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Expecting struct identifier");

    name = token.word;
    tokens.pop();

    token = tokens.front();
    if(token.type != "OPEN_BRACE")
        mad("Expected '{' after struct name");

    tokens.pop();

    token = tokens.front();

    vector<string> funCalls;

    while(token.type != "CLOSE_BRACE") {
       Declaration decl;
       decl.parse(tokens, funCalls);
       declarations.push_back(decl);
       token = tokens.front();
       if(token.type != "SEMICOLON")
            mad("Missing ';'");
       tokens.pop();
       token = tokens.front();
    }
}



string Struct::translate(int& tabs) {
    string code = "typedef " + name + " {\n";
    tabs++;
    for(int i = 0; i < declarations.size(); i++) {
        code += printTabs(tabs) + declarations[i].translate(tabs, true) + "\n";
    }
    tabs--;
    code += "}";
    return code;
}
