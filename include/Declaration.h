#ifndef DECLARATION_H
#define DECLARATION_H
#include "IntDecl.h"
#include "StructDecl.h"
#include "BoolDecl.h"
#include "Helper.h"
#include "Expression.h"


enum DeclarationType {
   STRUCT,
   INT,
   BOOL
};
class Declaration
{
    public:
        enum DeclarationType type;
        bool isPointer;
        string name;
        union {
            IntDecl* intDecl;
            StructDecl* structDecl;
            BoolDecl* boolDecl;
        };
        vector<int> dimensions;
        std::optional<Expression> expression;
        Declaration();
        Declaration(const Declaration &declaration);
        void parse(deque<Token>& tokens, vector<string>& _funCalls);
        string translate(int& tabs, bool addExpression);
};

#endif // DECLARATION_H
