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
string BinaryOperator::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string code1 = exp1.translate(fun_name, tabs, funCallNumber, previousCode);
    string code2 = exp2.translate(fun_name, tabs, funCallNumber, previousCode);

    return code1 + " " + op + " " + code2;
}

void BinaryOperator::changeVariablesName(string prefix) {
    exp1.changeVariablesName(prefix);
    exp2.changeVariablesName(prefix);
}
