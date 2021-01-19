#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "Const.h"

class UnaryOperator;
class BinaryOperator;

enum ExpressionType {
    CONSTANT,
    UNARY_OPERATOR,
    BINARY_OPERATOR
};

class Expression
{
    public:
        enum ExpressionType type;
        union {
            Const* constant;
            UnaryOperator* unaryOperator;
            BinaryOperator* binaryOperator;
        };

        Expression();
        void parse(queue<Token>& tokens);
        Expression parseExpression(queue<Token>& tokens);
        Expression parseTerm(queue<Token>& tokens);
        Expression parseFactor(queue<Token>& tokens);
        string translate();
};

#endif // EXPRESSION_H
