#ifndef DECLARATION_H
#define DECLARATION_H
#include "Variable.h"
#include "Helper.h"
#include "Expression.h"
class Declaration
{
    public:
        Variable var;
        vector<int> dimensions;
        std::optional<Expression> expression;
        Declaration();
        void parse(queue<Token>& tokens, vector<string>& _funCalls);
        string translate(int& tabs, bool addExpression);
};

#endif // DECLARATION_H
