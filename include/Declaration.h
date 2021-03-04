#ifndef DECLARATION_H
#define DECLARATION_H
#include "IntDecl.h"
#include "StructDecl.h"
#include "Helper.h"
#include "Expression.h"


enum DeclarationType {
   STRUCT,
   INT
};
class Declaration
{
    public:
        enum DeclarationType type;
        union {
            IntDecl* intDecl;
            StructDecl* structDecl;
        };
        vector<int> dimensions;
        std::optional<Expression> expression;
        Declaration();
        void parse(queue<Token>& tokens, vector<string>& _funCalls, string _type, string _name);
        string translate(int& tabs, bool addExpression);
};

#endif // DECLARATION_H
