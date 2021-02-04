#ifndef UNARYOPERATOR_H
#define UNARYOPERATOR_H
#include "Helper.h"
#include "Expression.h"

class UnaryOperator
{
    public:
        Expression expression;
        string op;
        UnaryOperator();
        void parse(queue<Token>& tokens);
        string translate(string fun_name, int& tabs);
};

#endif // UNARYOPERATOR_H
