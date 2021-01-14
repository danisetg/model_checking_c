#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "Const.h"

class Expression
{
    public:
        Const constant;
        Expression();
        Expression(const Const &_constant);
        void parse(queue<Token>& tokens);
        string translate();
};

#endif // EXPRESSION_H
