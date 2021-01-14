#ifndef RETURN_H
#define RETURN_H
#include "Expression.h"

class Return
{
    public:
        Expression expression;
        Return();
        Return(Expression &_expression);
        void parse(queue<Token>& tokens);
        string translate(string fun_name, int& tabs);
};

#endif // RETURN_H
