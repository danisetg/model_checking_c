#ifndef WHILE_H
#define WHILE_H
#include "Statement.h"
#include "Expression.h"

class While
{
    public:
        Expression endCondition;
        vector<Statement> whileBody;
        While();
        While(const While &whileStatement);
        void parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls);
        string translate(string fun_name,int& tabs, int& funCallNumber, string& previousCode);
        void changeVariablesName(string prefix);
};

#endif // WHILE_H
