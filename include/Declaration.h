#ifndef DECLARATION_H
#define DECLARATION_H
#include "Variable.h"
#include "Helper.h"
#include "Expression.h"
class Declaration
{
    public:
        Variable var;
        std::optional<Expression> expression;
        Declaration();
        void parse(queue<Token>& tokens);
        string translate(int& tabs);
};

#endif // DECLARATION_H
