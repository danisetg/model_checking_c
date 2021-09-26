#include "Const.h"
Const::Const(string _value)
{
    value = _value;
}
Const::Const()
{
}
void Const::parse(deque<Token>& tokens) {
    if(tokens.empty())
        mad("Constant is empty");

    Token token = tokens.front();

    if(token.type != "INTEGER" && token.type != "BOOLEAN_TRUE" && token.type != "BOOLEAN_FALSE")
        mad("Not a constant value");

    value = token.word;
    tokens.pop_front();
}

string Const::translate() {
    return value;
}
