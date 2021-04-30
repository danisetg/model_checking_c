#include "Scan.h"

Scan::Scan()
{
    //ctor
}

void Scan::parse(deque<Token>& tokens) {
    if(tokens.empty())
        mad("Missing variable");

    Token token = tokens.front();

    if(token.type != "SCANF_KEYWORD")
        mad("Not a scanf function");

    tokens.pop_front();

    token = tokens.front();

    if(token.type != "OPEN_PARENTHESIS")
        mad("Missing (");

    tokens.pop_front();

    token = tokens.front();
    while(token.type != "COMMA") {
        tokens.pop_front();
        token = tokens.front();
    }

    while(token.type == "COMMA") {
        tokens.pop_front();
        token = tokens.front();
        if(token.type != "BITWISE_AND")
            mad("Missing reference &");
        tokens.pop_front();
        token = tokens.front();
        variables.push_back(token.word);
        tokens.pop_front();
        token = tokens.front();
    }
    if(token.type != "CLOSE_PARENTHESIS")
        mad("Missing ')'");
    tokens.pop_front();
}

string Scan::translate(int& tabs) {
    string code = "";
    for(int i = 0; i < variables.size(); i++) {
        code += printTabs(tabs) + "run input(ret_input, 1, 10);\n";
        code += printTabs(tabs) + "ret_input ? " + variables[i] + ";\n";
    }
    return code;
}

void Scan::changeVariablesName(string prefix) {
    for(int i = 0; i < variables.size(); i++) {
        variables[i] = prefix + "_" + variables[i];
    }
}
