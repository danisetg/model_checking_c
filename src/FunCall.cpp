#include "FunCall.h"

FunCall::FunCall()
{
    //ctor
}

void FunCall::parse(string _name, deque<Token>& tokens, vector<string>& _funCalls) {
    if(tokens.empty())
        mad("Function is empty");

    name = _name;

    Token token = tokens.front();
    if(token.type != "OPEN_PARENTHESIS")
        mad("Missing '('");
    tokens.pop_front();

    token = tokens.front();
    while(token.type != "CLOSE_PARENTHESIS") {
        Expression exp;
        exp.parse(tokens, _funCalls);
        arguments.push_back(exp);
        token = tokens.front();
        if(token.type != "COMMA" && token.type != "CLOSE_PARENTHESIS")
            mad("Arguments must be separated by ','");
        else if(token.type == "COMMA")
            tokens.pop_front();
        token = tokens.front();
    }
    tokens.pop_front();
}

string FunCall::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string code = printTabs(tabs) + "run " + name + "(ret_" + name;

    for(int i = 0; i < arguments.size(); i++) {
            code += ", " + arguments[i].translate(fun_name, tabs, funCallNumber, previousCode);
    }

    code += ");\n";

    code += printTabs(tabs) + "ret_" + name + " ? temp" + to_string(funCallNumber) + ";\n";
    previousCode += code;

    string ret = "temp" + to_string(funCallNumber);
    funCallNumber++;

    return ret;
}
