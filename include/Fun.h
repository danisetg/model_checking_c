#ifndef FUN_H
#define FUN_H
#include <string>
#include <Helper.h>
#include "Statement.h"
#include "Variable.h"
class Fun
{
    public:
        string name;
        map<string, bool> chanDeclared;
        vector<Statement> statements;
        vector<Variable> parameters;
        vector<string> funCalls;
        Fun();
        void parse(deque<Token>& tokens, string _name);
        string translate(int& tabs);
};

#endif // FUN_H
