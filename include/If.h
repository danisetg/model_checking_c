#ifndef IF_H
#define IF_H
#include "Expression.h"
#include "Statement.h"

class If
{
    public:
        Expression condition;
        Statement ifBody;
        std::optional<Statement> elseBody;
        If();
        void parse(queue<Token>& tokens);
        string translate(string fun_name,int& tabs);
};

#endif // IF_H
