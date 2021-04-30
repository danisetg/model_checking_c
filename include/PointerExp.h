#ifndef POINTEREXP_H
#define POINTEREXP_H
#include "Helper.h"
#include "Expression.h"

class PointerExp
{
    public:
        Expression exp;
        string varName;
        PointerExp();
         void parse(Expression _exp, deque<Token>& tokens);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
        void changeVariablesName(string prefix);
};

#endif // POINTEREXP_H
