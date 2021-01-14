#include "Program.h"
#include "Fun.h"
#include "Helper.h"
using std::cout;
using std::endl;
Program::Program(Fun &_f)
{
    f = _f;
}
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
    return f.translate(tabs);
}
