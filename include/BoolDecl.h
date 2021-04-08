#ifndef BOOLDECL_H
#define BOOLDECL_H
#include "Helper.h"

class BoolDecl
{
    public:
        string name;
        BoolDecl();
        void parse(deque<Token>& tokens);
        string translate();
};

#endif // BOOLDECL_H
