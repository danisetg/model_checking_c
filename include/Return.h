#ifndef RETURN_H
#define RETURN_H
#include "Helper.h"
#include "Expression.h"
class Return
{
    public:
        Expression expression;
        Return();
        Return(const Return &ret);
        void parse(deque<Token>& tokens, vector<string>& _funCalls);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
        string translateConditional(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
        void changeVariablesName(string prefix);
};

#endif // RETURN_H
