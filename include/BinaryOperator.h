#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H
#include "Expression.h"

class BinaryOperator
{
    public:
        string op;
        Expression exp1;
        Expression exp2;
        BinaryOperator();
        BinaryOperator(string _op, Expression& _exp1, Expression& _exp2);
        void parse(queue<Token>& tokens);
        string translate(int& tabs);
};

#endif // BINARYOPERATOR_H
