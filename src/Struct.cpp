#include "Struct.h"

Struct::Struct()
{
    //ctor
}

void Struct::parse(queue<Token>& tokens, string _name) {

    name = _name;

    Token token = tokens.front();
    if(token.type != "OPEN_BRACE")
        mad("Expected '{' after struct name");

    tokens.pop();

    token = tokens.front();

    vector<string> funCalls;

    while(token.type != "CLOSE_BRACE") {
       Declaration decl;
       if(token.type != "STRUCT_KEYWORD" && token.type != "INT_KEYWORD")
            mad("Unknown type");
       string type = token.type;
       tokens.pop();
       token = tokens.front();
       tokens.pop();
       decl.parse(tokens, funCalls, type, token.word);
       declarations.push_back(decl);
       token = tokens.front();
       cout<<token.word<<endl;
       if(token.type != "SEMICOLON")
            mad("Missing ';'");
       tokens.pop();
       token = tokens.front();
    }
    tokens.pop();
    token = tokens.front();
    if(token.type != "SEMICOLON")
        mad("Missing ';'");
    tokens.pop();
}



string Struct::translate(int& tabs) {
    string code = "typedef " + name + " {\n";
    cout<<name<<endl;
    tabs++;
    for(int i = 0; i < declarations.size(); i++) {
        code += declarations[i].translate(tabs, true) + "\n";
    }
    tabs--;
    code += "}";
    return code;
}
