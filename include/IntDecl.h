#ifndef INTDECL_H
#define INTDECL_H
#include "Helper.h"

class IntDecl
{
    public:
        string name;
        IntDecl();
        void parse(deque<Token>& tokens);
        string translate();
};

#endif // INTDECL_H
