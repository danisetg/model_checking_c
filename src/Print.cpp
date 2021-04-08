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

    message = "";
    while(token.type != "SEMICOLON" && !tokens.empty()) {
        message += token.word;
        if(token.type == "IDENTIFIER")
            message += " ";
        cout<<token.word<<" "<<message<<endl;
        tokens.pop_front();
        token = tokens.front();
    }
}

string Print::translate(int& tabs) {
    return printTabs(tabs) + "printf" + message + ";\n";
}
