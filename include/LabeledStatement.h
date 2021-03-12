#ifndef LABELEDSTATEMENT_H
#define LABELEDSTATEMENT_H
#include "Helper.h"
#include "Statement.h"

class LabeledStatement
{
    public:
        string labelName;
        Statement statement;
        LabeledStatement();
        void parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
};

#endif // LABELEDSTATEMENT_H
