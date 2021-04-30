#ifndef BOOLDECL_H
#define BOOLDECL_H
#include "Helper.h"

class BoolDecl
{
    public:
        BoolDecl();
        void parse(deque<Token>& tokens, string name);
        string translate(string name);
};

#endif // BOOLDECL_H
