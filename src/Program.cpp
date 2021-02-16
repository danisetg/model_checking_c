#include "Program.h"
#include "Fun.h"
#include "Helper.h"
#include "Return.h"
#include "Expression.h"
#include "UnaryOperator.h"
#include "Program.h"
#include "Variable.h"


Program::Program()
{
}

void Program::parse(queue<Token>& tokens) {

    if(tokens.empty())
        mad("Program is empty");

    Token token = tokens.front();
    while(token.type == "INT_KEYWORD") {
        tokens.pop();

        token = tokens.front();

        if(token.type != "IDENTIFIER")
            mad("Missing function identifier");

        string name = token.word;
        tokens.pop();

        token = tokens.front();

        if(token.type == "OPEN_PARENTHESIS") {
            Fun _f;
            _f.parse(tokens, name);
            f.push_back(_f);
        } else if(token.type == "SEMICOLON" || token.type == "ASSIGNMENT") {
            Variable v;
            v.name = name;
            Declaration decl;
            decl.var = v;
            if(token.type == "ASSIGNMENT") {
                tokens.pop();
                Expression exp;
                vector<string> fcall;
                exp.parse(tokens, fcall);
                decl.expression = exp;
            }
            d.push_back(decl);
            tokens.pop();
        } else
            mad("Expecting function or variable declaration");

        if(tokens.empty())
            break;
        token = tokens.front();
    }
}

string Program::translate(int& tabs) {
    //Right now program only consists of a function
    //so it returns its function's translate
    string code = "";
    for(int i = 0; i < d.size(); i++) {
        code += d[i].translate(tabs, true) + "\n";
       // cout<<f[i].name<<endl;
    }
    for(int i = 0; i < f.size(); i++) {
        string tmp = "";
        code += f[i].translate(tabs) + "\n";
       // cout<<f[i].name<<endl;
    }

   // cout<<code<<endl;
    return code;
}
