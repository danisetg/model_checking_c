#ifndef STRUCTEXP_H
#define STRUCTEXP_H
#include "Helper.h"
#include "Expression.h"
class StructExp
{
    public:
        Expression exp;
        string varName;
        StructExp();
        void parse(Expression _exp, deque<Token>& tokens);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
};

#endif // STRUCTEXP_H
