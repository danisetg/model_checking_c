#ifndef SWITCH_H
#define SWITCH_H
#include "Expression.h"
#include "Statement.h"
class Switch
{
    public:
        Expression condition;
        vector<Expression> cases;
        vector<vector<Statement> > caseStatements;
        vector<Statement> defaultStatements;
        Switch();
        void parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls);
        string translate(string fun_name,int& tabs, int& funCallNumber, string& previousCode);
};

#endif // SWITCH_H
