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

void Program::parse(deque<Token>& tokens) {

    if(tokens.empty())
        mad("Program is empty");

    Token token = tokens.front();
    while(token.type == "INT_KEYWORD" || token.type == "STRUCT_KEYWORD") {

        string type = token.type;
        tokens.pop_front();

        Token token1 = tokens.front();
        if(token1.type != "IDENTIFIER")
                mad("Missing identifier");

        string name = token1.word;
        tokens.pop_front();

        Token token2 = tokens.front();
        vector<string> funCalls;

        if(token2.type != "OPEN_BRACE" && token2.type != "OPEN_PARENTHESIS") {
            tokens.push_front(token1);
            tokens.push_front(token);
            Declaration decl;
            decl.parse(tokens, funCalls);
            d.push_back(decl);
            token = tokens.front();
            if(token.type != "SEMICOLON")
                mad("Missing ';'");
            tokens.pop_front();
        } else if (type == "STRUCT_KEYWORD" && token.type == "OPEN_BRACE") {
            Struct _s;
            _s.parse(tokens, name);
            s.push_back(_s);
        } else if (type == "INT_KEYWORD" && token.type == "OPEN_PARENTHESIS" ) {
            Fun _f;
            _f.parse(tokens, name);
            f.push_back(_f);
        }
        if(tokens.empty())
            break;
        token = tokens.front();
        cout<<token.word<<endl;
    }
}

string Program::translate(int& tabs) {
    //Right now program only consists of a function
    //so it returns its function's translate
    string code = "";

    for(int i = 0; i < s.size(); i++) {
        code += s[i].translate(tabs) + "\n";
        //cout<<" "<<s[i].name<<endl;
    }

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
