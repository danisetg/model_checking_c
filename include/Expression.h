#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "Const.h"

class UnaryOperator;

enum ExpressionType {
    CONSTANT,
    UNARY_OPERATOR
};

class Expression
{
    public:
        enum ExpressionType type;
        union {
            Const* constant;
            UnaryOperator* unaryOperator;
        };

        Expression();
        void parse(queue<Token>& tokens);
        string translate();
};

#endif // EXPRESSION_H
