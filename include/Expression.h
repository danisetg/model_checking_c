#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "Const.h"
#include "Helper.h"
class UnaryOperator;
class BinaryOperator;
class Assignment;
class Variable;
class Conditional;
class FunCall;
class Array;

enum ExpressionType {
    CONSTANT,
    UNARY_OPERATOR,
    BINARY_OPERATOR,
    ASSIGNMENT,
    VARIABLE,
    CONDITIONAL,
    FUN_CALL,
    ARRAY
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
            Conditional* cond;
            FunCall* funCall;
            Array* arr;
        };

        Expression();
        void parse(queue<Token>& tokens, vector<string>& _funCalls);
        Expression parseExpression(queue<Token>& tokens, vector<string>& _funCalls);
        Expression parseTerm(queue<Token>& tokens, vector<string>& _funCalls);
        Expression parseFactor(queue<Token>& tokens, vector<string>& _funCalls);
        Expression parseAddition(queue<Token>& tokens, vector<string>& _funCalls);
        Expression parseRelationalEqualities(queue<Token>& tokens, vector<string>& _funCalls);
        Expression parseRelationalInequalities(queue<Token>& tokens, vector<string>& _funCalls);
        Expression parseAnd(queue<Token>& tokens, vector<string>& _funCalls);
        Expression parseOr(queue<Token>& tokens, vector<string>& _funCalls);
        Expression parseAssignment(queue<Token>& tokens, vector<string>& _funCalls);
        Expression parseConditional(queue<Token>& tokens, vector<string>& _funCalls);

        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
};

#endif // EXPRESSION_H
