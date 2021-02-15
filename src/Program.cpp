#include "Program.h"
#include "Fun.h"
#include "Helper.h"
#include "Return.h"
#include "Expression.h"
#include "UnaryOperator.h"
#include "Program.h"

Program::Program()
{
}

void Program::parse(queue<Token>& tokens) {

    if(tokens.empty())
        mad("Program is empty");

    Token token = tokens.front();
    while(token.type == "INT_KEYWORD") {
        Fun _f;
        _f.parse(tokens);
        f.push_back(_f);
        if(tokens.empty())
            break;
        token = tokens.front();
    }
}

string Program::translate(int& tabs) {
    //Right now program only consists of a function
    //so it returns its function's translate
    string code = "";
    for(int i = 0; i < f.size(); i++) {
        code += f[i].translate(tabs) + "\n";
       // cout<<f[i].name<<endl;
    }
   // cout<<code<<endl;
    return code;
}
