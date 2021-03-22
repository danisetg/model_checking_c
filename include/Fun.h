#ifndef FUN_H
#define FUN_H
#include <string>
#include <Helper.h>
#include "Statement.h"
#include "Declaration.h"
#include "Return.h"

enum FunctionType {
    VOID,
    INTEGER
};
class Fun
{
    public:
        string name;
        enum FunctionType type;
        map<string, bool> chanDeclared;
        vector<Statement> statements;
        vector<Declaration> parameters;
        vector<string> funCalls;
        Fun();
        void parse(deque<Token>& tokens, string _name, string _type);
        string translate(int& tabs);
};

#endif // FUN_H
