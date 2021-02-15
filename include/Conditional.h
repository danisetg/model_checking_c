#ifndef CONDITIONAL_H
#define CONDITIONAL_H
#include "Expression.h"
#include "Helper.h"

class Conditional
{
    public:
        Expression condition;
        Expression trueAssign;
        Expression falseAssign;
        Conditional();
        Conditional(Expression& e1, Expression& e2, Expression& e3);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
};

#endif // CONDITIONAL_H
