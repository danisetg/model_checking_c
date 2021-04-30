#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include "Expression.h"
#include "Variable.h"
#include "Array.h"
class Assignment
{
    public:
        Expression leftSide;
        Expression exp;
        Assignment(Expression& _leftSide, Expression& _exp);
        Assignment();
        void parse(deque<Token>& tokens);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
        string translateConditional(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
        void changeVariablesName(string prefix);
};

#endif // ASSIGNMENT_H
