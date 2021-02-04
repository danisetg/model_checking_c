#include "BinaryOperator.h"
#include "Helper.h"
#include "Assignment.h"
BinaryOperator::BinaryOperator()
{
}
BinaryOperator::BinaryOperator(string _op, Expression& _exp1, Expression& _exp2)
{
    op = _op;
    exp1 = _exp1;
    exp2 = _exp2;
}
string BinaryOperator::translate(string fun_name, int& tabs) {
    string code = "";
    if(exp2.type == ASSIGNMENT)
        code = exp2.translate(fun_name, tabs) + ");\n" + printTabs(tabs) + "(" + exp1.translate(fun_name, tabs) + " " + op + " " + exp2.assignment->var.translate();
    else
        code = exp1.translate(fun_name, tabs) + " " + op + " " + exp2.translate(fun_name, tabs);
    return code;
}
