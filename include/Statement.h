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

enum StatementType {
    EXPRESSION,
    RETURN,
    DECLARATION,
    IF,
    FOR,
    WHILE,
    DO_WHILE,
    CONTINUE,
    BREAK
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
        };
        Statement();
        void parse(queue<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
};

#endif // STATEMENT_H
