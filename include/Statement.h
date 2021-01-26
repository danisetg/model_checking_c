#ifndef STATEMENT_H
#define STATEMENT_H
#include "Helper.h"

class Expression;
class Return;
class Declaration;

enum StatementType {
    EXPRESSION,
    RETURN,
    DECLARATION
};

class Statement
{
    public:
        enum StatementType type;
        union {
            Expression* expression;
            Return* ret;
            Declaration* decl;
        };
        Statement();
        void parse(queue<Token>& tokens);
        string translate(string fun_name, int& tabs);
};

#endif // STATEMENT_H
