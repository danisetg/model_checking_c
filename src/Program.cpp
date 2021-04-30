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
    while(token.type == "INT_KEYWORD" || token.type == "STRUCT_KEYWORD" || token.type == "VOID_KEYWORD") {

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
        } else if (type == "STRUCT_KEYWORD" && token2.type == "OPEN_BRACE") {
            Struct _s;
            _s.parse(tokens, name);
            s.push_back(_s);
        } else if ((type == "INT_KEYWORD" || type == "VOID_KEYWORD") && token2.type == "OPEN_PARENTHESIS" ) {
            Fun _f;
            _f.parse(tokens, name, type);
            f.push_back(_f);
        }
        if(tokens.empty())
            break;
        token = tokens.front();
    }
}
string Program::inputFunction(int& tabs) {
    string code = "proctype input(chan in_input; int min; int max) {\n";
    tabs++;
    code += printTabs(tabs) + "atomic {\n";
	tabs++;
	code += printTabs(tabs) + "int value = min;\n";
	code += printTabs(tabs) + "do\n";
	tabs++;
	code += printTabs(tabs) + "::value < max -> value++;\n";
	code += printTabs(tabs) + "::break;\n";
	tabs--;
	code += printTabs(tabs) + "od;\n";
	code += printTabs(tabs) + "in_input ! value;\n";
	tabs--;
    code += printTabs(tabs) + "}\n";
	tabs--;
	code+= "}\n";
	return code;
}
string Program::translate(int& tabs, bool translateDefines) {
    //Right now program only consists of a function
    //so it returns its function's translate
    string code = "";
    code += inputFunction(tabs);
    for(int i = 0; i < s.size(); i++) {
        code += s[i].translate(tabs) + "\n";
        //cout<<" "<<s[i].name<<endl;
    }

    vector<string> pointers_types = getPointerTypes();

    for(int i = 0; i < pointers_types.size(); i++) {
        code += pointers_types[i] + " " + pointers_types[i] + "_mem[9];\n";
        code += "int " + pointers_types[i] + "_valid[9];\n";
    }

    for(int i = 0; i < d.size(); i++) {
        code += d[i].translate(tabs, true) + ";\n";
       // cout<<f[i].name<<endl;
    }

    if(translateDefines) {
        for(int i = 0; i < def.size(); i++) {
            code += def[i].translate();
        }
    }

    for(int i = 0; i < f.size(); i++) {
        string tmp = "";
        code += f[i].translate(tabs) + "\n";
       // cout<<f[i].name<<endl;
    }

    code += "init {\n";
    tabs++;
    code += printTabs(tabs) + "chan ret_main = [0] of { bit };\n";
    code += printTabs(tabs) + "run main(ret_main);\n";
    code += printTabs(tabs) + "ret_main ? 0;\n";
    tabs--;
    code += "}";

   // cout<<code<<endl;
    return code;
}

void Program::changeLocalVariablesName() {
     for(int i = 0; i < f.size(); i++) {
        f[i].changeVariablesName();
     }
}
