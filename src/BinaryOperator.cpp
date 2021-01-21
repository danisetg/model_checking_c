#include "BinaryOperator.h"
#include "Helper.h"
BinaryOperator::BinaryOperator()
{
}
BinaryOperator::BinaryOperator(string _op, Expression& _exp1, Expression& _exp2)
{
    op = _op;
    exp1 = _exp1;
    exp2 = _exp2;
}
string BinaryOperator::translate() {
    return exp1.translate() + " " + op + " " + exp2.translate();
}
