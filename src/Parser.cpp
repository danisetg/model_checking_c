#include "Program.h"
#include "Token.h"
#include <queue>
#include "Helper.h"
#include <iostream>
#include "Program.h"
#include "Fun.h"
#include "Return.h"
#include "Expression.h"
#include "Const.h"
using std::queue;
using std::cout;
using std::endl;




Program parseProgram(queue<Token>& tokens) {

    if(tokens.empty())
        mad("Program is empty");

    Fun f = parseFunction(tokens);

    Program p = Program(f);

    return p;
}




