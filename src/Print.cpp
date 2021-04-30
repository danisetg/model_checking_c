#include "Print.h"

Print::Print()
{
    //ctor
}

void Print::parse(deque<Token>& tokens) {
    if(tokens.empty())
        mad("Missing variable");

    Token token = tokens.front();

    if(token.type != "PRINTF_KEYWORD")
        mad("Not a printf function");

    tokens.pop_front();
    token = tokens.front();
    if(token.type != "OPEN_PARENTHESIS")
        mad("Missing (");
    tokens.pop_front();
    token = tokens.front();

    if(token.type != "QUOTES")
        mad("Missing quotes");
    tokens.pop_front();
    token = tokens.front();

    message = "";
    while(token.type != "QUOTES" && !tokens.empty()) {
        message += token.word;
        if(token.type == "IDENTIFIER")
            message += " ";
        cout<<token.word<<" "<<message<<endl;
        tokens.pop_front();
        token = tokens.front();
    }
    message += token.word;
    tokens.pop_front();
    token = tokens.front();
    while(token.type == "COMMA") {
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

string Print::translate(int& tabs) {
    string code = printTabs(tabs) + "printf(\"" + message;
    for(int i = 0; i < variables.size(); i++) {
        code += "," + variables[i];
    }
    code += ");\n";
    return code;
}

void Print::changeVariablesName(string prefix) {
    for(int i = 0; i < variables.size(); i++) {
        variables[i] = prefix + "_" + variables[i];
    }
}
