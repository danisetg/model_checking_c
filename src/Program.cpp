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

    Fun _f;
    _f.parse(tokens);
    f = _f;
}

string Program::translate(int& tabs) {
    //Right now program only consists of a function
    //so it returns its function's translate
    return f.translate(tabs);
}
