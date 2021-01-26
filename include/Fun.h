#ifndef FUN_H
#define FUN_H
#include <string>
#include <Helper.h>
#include "Statement.h"

class Fun
{
    public:
        string name;
        vector<Statement> statements;
        Fun();
        void parse(queue<Token>& tokens);
        string translate(int& tabs);
};

#endif // FUN_H
