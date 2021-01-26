#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include "Expression.h"
#include "Variable.h"
class Assignment
{
    public:
        Variable var;
        Expression exp;
        Assignment(Variable& _var, Expression& _exp);
        Assignment();
        void parse(queue<Token>& tokens);
        string translate(int& tabs);
};

#endif // ASSIGNMENT_H
