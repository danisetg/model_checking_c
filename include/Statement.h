#ifndef STATEMENT_H
#define STATEMENT_H
#include "Helper.h"

class Expression;
class Return;
class Declaration;
class If;
class For;
class While;
class Continue;
class Break;
class DoWhile;
class LabeledStatement;
class Goto;
class Switch;

enum StatementType {
    EXPRESSION,
    RETURN,
    DECLARATION,
    IF,
    FOR,
    WHILE,
    DO_WHILE,
    CONTINUE,
    BREAK,
    LABELED_STATEMENT,
    GOTO,
    SWITCH
};

class Statement
{
    public:
        enum StatementType type;
        union {
            Expression* expression;
            Return* ret;
            Declaration* decl;
            If* ifStatement;
            For* forStatement;
            Continue* continueStatement;
            Break* breakStatement;
            While* whileStatement;
            DoWhile* doWhileStatement;
            LabeledStatement* labeledStatement;
            Goto* gto;
            Switch* switchStatement;
        };
        Statement();
        void parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
};

#endif // STATEMENT_H
