#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "Const.h"

class UnaryOperator;
class BinaryOperator;
class Assignment;
class Variable;

enum ExpressionType {
    CONSTANT,
    UNARY_OPERATOR,
    BINARY_OPERATOR,
    ASSIGNMENT,
    VARIABLE
};

class Expression
{
    public:
        enum ExpressionType type;
        union {
            Const* constant;
            UnaryOperator* unaryOperator;
            BinaryOperator* binaryOperator;
            Assignment* assignment;
            Variable* variable;
        };

        Expression();
        void parse(queue<Token>& tokens);
        Expression parseExpression(queue<Token>& tokens);
        Expression parseTerm(queue<Token>& tokens);
        Expression parseFactor(queue<Token>& tokens);
        Expression parseAddition(queue<Token>& tokens);
        Expression parseRelationalEqualities(queue<Token>& tokens);
        Expression parseRelationalInequalities(queue<Token>& tokens);
        Expression parseAnd(queue<Token>& tokens);
        Expression parseOr(queue<Token>& tokens);
        Expression parseAssignment(queue<Token>& tokens);

        string translate(int& tabs);
};

#endif // EXPRESSION_H
