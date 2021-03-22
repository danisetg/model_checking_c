#include "Struct.h"

Struct::Struct()
{
    //ctor
}

void Struct::parse(deque<Token>& tokens, string _name) {

    name = _name;

    Token token = tokens.front();
    if(token.type != "OPEN_BRACE")
        mad("Expected '{' after struct name");

    tokens.pop_front();

    token = tokens.front();

    vector<string> funCalls;
    vector<pair<string, string> > members;
    while(token.type != "CLOSE_BRACE") {
       Declaration decl;
       if(token.type != "STRUCT_KEYWORD" && token.type != "INT_KEYWORD")
            mad("Unknown type");
       decl.parse(tokens, funCalls);
       if(decl.type == INT)
            members.push_back(make_pair("int", decl.intDecl->name));
       else
            members.push_back(make_pair(decl.structDecl->structName, decl.structDecl->name));
       declarations.push_back(decl);
       token = tokens.front();
       cout<<token.word<<endl;
       if(token.type != "SEMICOLON")
            mad("Missing ';'");
       tokens.pop_front();
       token = tokens.front();
    }
    saveStructType(name, members);
    tokens.pop_front();
    token = tokens.front();
    if(token.type != "SEMICOLON")
        mad("Missing ';'");
    tokens.pop_front();
}



string Struct::translate(int& tabs) {
    string code = "typedef " + name + " {\n";
    cout<<name<<endl;
    tabs++;
    for(int i = 0; i < declarations.size(); i++) {
        code += declarations[i].translate(tabs, true) + ";\n";
    }
    tabs--;
    code += "}";
    return code;
}
