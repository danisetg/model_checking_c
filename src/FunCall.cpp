#include "FunCall.h"
#include "Variable.h"
FunCall::FunCall()
{
    //ctor
}

void FunCall::parse(string _name, deque<Token>& tokens, vector<string>& _funCalls) {
    if(tokens.empty())
        mad("Function is empty");

    name = _name;

    Token token = tokens.front();

    if(name == "malloc") {
        Expression exp;
        exp.type = VARIABLE;
        exp.variable = new Variable();
        while(token.type != "SEMICOLON") {
            if(token.type == "INT_KEYWORD") {
                exp.variable->name = "int";
                arguments.push_back(exp);
            } else if(token.type == "STRUCT_KEYWORD") {
                tokens.pop_front();
                token = tokens.front();
                exp.variable->name = token.word;
                arguments.push_back(exp);
            }
            tokens.pop_front();
            token = tokens.front();
        }
    } else {
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




}

string FunCall::translateMalloc(int& tabs, int& funCallNumber, string type) {
        string code = printTabs(tabs) + "atomic {\n";
        tabs++;
        code += printTabs(tabs) + "temp" + to_string(funCallNumber) + " = 1;\n";
        code += printTabs(tabs) + "do\n";
        tabs++;
        code += printTabs(tabs) + ":: (temp" + to_string(funCallNumber) + " >= 9) -> break;\n";
        code += printTabs(tabs) + "::else ->\n";
        tabs++;
        code += printTabs(tabs) + "if\n";
        tabs++;
        code += printTabs(tabs) + "::(" + type + "_valid[temp" + to_string(funCallNumber) + "] == 0) ->\n";
        tabs++;
        code += printTabs(tabs) + type + "_valid[temp" + to_string(funCallNumber) + "] = 1;\n";
        code += printTabs(tabs) + "break;\n";
        tabs--;
        code += printTabs(tabs) + "::else -> temp" + to_string(funCallNumber) + "++;\n";
        tabs--;

        code += printTabs(tabs) + "fi;\n";
        tabs--;
        tabs--;
        code += printTabs(tabs) + "od;\n";
        code += printTabs(tabs) + "assert(temp" + to_string(funCallNumber) + " < 9);\n";
        tabs--;
        code += printTabs(tabs) + "};\n";
        return code;
}



string FunCall::translateFree(int& tabs, string varName) {
    string code = "d_step {\n";
    tabs++;
    string type = getPointerType(varName);
    code += printTabs(tabs) + type + "_valid[" + varName + "] = 0;\n";
    if(type == "int") {
        code += printTabs(tabs) + "int_mem[" + varName + "] = 0;\n";
    } else {
        vector<pair<string, string> > members = getStructMembers(type);
        for(int i = 0; i < members.size(); i++) {
            code += printTabs(tabs) + type + "_mem[" + varName + "]." + members[i].second + " = 0;\n";
        }

    }
    tabs--;
    code += printTabs(tabs) + "}";
    return code;
}

string FunCall::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    cout<<name<<endl;
    if(name == "malloc") {
       previousCode += translateMalloc(tabs, funCallNumber, arguments[0].variable->name);
       string ret = "temp" + to_string(funCallNumber);
       funCallNumber++;
       return ret;
    } else if(name == "free") {
       return translateFree(tabs, arguments[0].variable->name);
    } else {
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
}
