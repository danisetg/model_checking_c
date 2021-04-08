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
class StructExp;
class Increment;
class Decrement;
class PointerExp;

enum ExpressionType {
    CONSTANT,
    UNARY_OPERATOR,
    BINARY_OPERATOR,
    ASSIGNMENT,
    VARIABLE,
    CONDITIONAL,
    FUN_CALL,
    ARRAY,
    STRUCT_EXPRESSION,
    INCREMENT,
    DECREMENT,
    POINTER_EXPRESSION
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
            StructExp* structExp;
            Increment* increment;
            Decrement* decrement;
            PointerExp* pointerExp;
        };

        Expression();
        void parse(deque<Token>& tokens, vector<string>& _funCalls);
        Expression parseExpression(deque<Token>& tokens, vector<string>& _funCalls);
        Expression parseTerm(deque<Token>& tokens, vector<string>& _funCalls);
        Expression parseFactor(deque<Token>& tokens, vector<string>& _funCalls);
        Expression parseSubFactor(deque<Token>& tokens, vector<string>& _funCalls, Expression& exp);
        Expression parseAddition(deque<Token>& tokens, vector<string>& _funCalls);
        Expression parseRelationalEqualities(deque<Token>& tokens, vector<string>& _funCalls);
        Expression parseRelationalInequalities(deque<Token>& tokens, vector<string>& _funCalls);
        Expression parseAnd(deque<Token>& tokens, vector<string>& _funCalls);
        Expression parseOr(deque<Token>& tokens, vector<string>& _funCalls);
        Expression parseAssignment(deque<Token>& tokens, vector<string>& _funCalls);
        Expression parseConditional(deque<Token>& tokens, vector<string>& _funCalls);

        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
};

#endif // EXPRESSION_H
