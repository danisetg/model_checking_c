#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H
#include "Expression.h"
#include "Helper.h"

class BinaryOperator
{
    public:
        string op;
        Expression exp1;
        Expression exp2;
        BinaryOperator();
        BinaryOperator(string _op, Expression& _exp1, Expression& _exp2);
        BinaryOperator(const BinaryOperator &binaryOperator);
        void parse(deque<Token>& tokens);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
        void changeVariablesName(string prefix);
};

#endif // BINARYOPERATOR_H
