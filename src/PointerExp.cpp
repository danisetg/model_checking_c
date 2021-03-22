#include "PointerExp.h"

PointerExp::PointerExp()
{
    //ctor
}

void PointerExp::parse(string name, deque<Token>& tokens) {
    if(tokens.empty())
        mad("Missing variable");
    pointerName = name;

    Token token = tokens.front();

    if(token.type != "ARROW")
        mad("Missing '->'");

    tokens.pop_front();

    token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Missing struct variable reference");

    varName = token.word;
    tokens.pop_front();
}

string PointerExp::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string type = getPointerType(pointerName);
    if(type == "-1")
        mad("Can't find pointer " + pointerName);

    return type + "_mem[" + pointerName + "]." + varName;
}
