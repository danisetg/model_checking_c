#ifndef IF_H
#define IF_H
#include "Expression.h"
#include "Statement.h"
#include "Helper.h"
class If
{
    public:
        Expression condition;
        vector<Statement> ifBody;
        vector<Statement> elseBody;
        If();
        void parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls);
        string translate(string fun_name,int& tabs, int& funCallNumber, string& previousCode);
        void changeVariablesName(string prefix);
};

#endif // IF_H
