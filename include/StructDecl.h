#ifndef STRUCTDECL_H
#define STRUCTDECL_H
#include "Helper.h"

class StructDecl
{
    public:
        string structName;
        string name;
        StructDecl();
        void parse(deque<Token>& tokens);
        string translate(bool isPointer);
};

#endif // STRUCTDECL_H
