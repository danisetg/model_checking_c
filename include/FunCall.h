#ifndef FUNCALL_H
#define FUNCALL_H
#include "Expression.h"

class FunCall
{
    public:
        string name;
        vector<Expression> arguments;
        FunCall();
        FunCall(const FunCall &FunCall);
        void parse(string _name, deque<Token>& tokens, vector<string>& _funCalls);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
        string translateMalloc(int& tabs, int& funCallNumber, string type);
        string translateFree(int& tabs, string varName);
        void changeVariablesName(string prefix);

};

#endif // FUNCALL_H
