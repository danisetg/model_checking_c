#ifndef DOWHILE_H
#define DOWHILE_H
#include "Statement.h"
#include "Expression.h"

class DoWhile
{
    public:
        Expression endCondition;
        vector<Statement> body;
        DoWhile();
        void parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls);
        string translate(string fun_name,int& tabs, int& funCallNumber, string& previousCode);
        void changeVariablesName(string prefix);
};

#endif // DOWHILE_H
