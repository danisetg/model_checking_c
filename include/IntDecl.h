#ifndef INTDECL_H
#define INTDECL_H
#include "Helper.h"

class IntDecl
{
    public:
        IntDecl();
        void parse(deque<Token>& tokens);
        string translate(string name);
};

#endif // INTDECL_H
