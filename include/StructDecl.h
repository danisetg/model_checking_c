#ifndef STRUCTDECL_H
#define STRUCTDECL_H
#include "Helper.h"

class StructDecl
{
    public:
        string structName;
        string name;
        StructDecl();
        void parse(queue<Token>& tokens);
        string translate();
};

#endif // STRUCTDECL_H
