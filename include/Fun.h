#ifndef FUN_H
#define FUN_H
#include <string>
#include <Helper.h>
#include "Return.h"

class Fun
{
    public:
        string name;
        Return statement;
        Fun();
        void parse(queue<Token>& tokens);
        string translate(int& tabs);
};

#endif // FUN_H
