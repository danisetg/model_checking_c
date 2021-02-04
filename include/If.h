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
        void parse(queue<Token>& tokens, vector<Statement>& statements);
        string translate(string fun_name,int& tabs);
};

#endif // IF_H
