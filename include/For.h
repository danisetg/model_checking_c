#ifndef FOR_H
#define FOR_H
#include "Statement.h"
#include "Expression.h"
class For
{
    public:
        std::optional<Statement> initialValue;
        std::optional<Expression> endCondition;
        std::optional<Expression> nextValue;

        vector<Statement> forBody;
        For();
        For(const For &forStatement);
        void parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls);
        string translate(string fun_name,int& tabs, int& funCallNumber, string& previousCode);
        void changeVariablesName(string prefix);
};

#endif // FOR_H
