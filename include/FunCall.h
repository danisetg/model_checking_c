#ifndef FUNCALL_H
#define FUNCALL_H
#include "Expression.h"

class FunCall
{
    public:
        string name;
        vector<Expression> arguments;
        FunCall();
        void parse(string _name, deque<Token>& tokens, vector<string>& _funCalls);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
};

#endif // FUNCALL_H
