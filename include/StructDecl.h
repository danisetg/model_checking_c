#ifndef STRUCTDECL_H
#define STRUCTDECL_H
#include "Helper.h"

class StructDecl
{
    public:
        string structName;
        StructDecl();
        void parse(deque<Token>& tokens);
        string translate(bool isPointer, string name);
};

#endif // STRUCTDECL_H
