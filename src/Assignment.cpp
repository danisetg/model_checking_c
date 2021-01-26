#include "Assignment.h"
#include "Helper.h"
Assignment::Assignment(Variable& _var, Expression& _exp)
{
    var = _var;
    exp = _exp;
}

Assignment::Assignment()
{
}


string Assignment::translate(int& tabs) {
    string code = "";
    if(exp.type == ASSIGNMENT)
        code = exp.translate(tabs) + ";\n" + printTabs(tabs) + var.translate() + " = " + exp.assignment->var.translate();
    else
        code = var.translate() + " = " + exp.translate(tabs);
    return code;
}
