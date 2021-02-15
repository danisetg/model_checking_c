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
        void parse(queue<Token>& tokens, vector<string>& _funCalls);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
};

#endif // UNARYOPERATOR_H
