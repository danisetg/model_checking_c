#ifndef STRUCT_H
#define STRUCT_H
#include "Helper.h"
#include "Declaration.h"

class Struct
{
    public:
        string name;
        vector<Declaration> declarations;
        Struct();
        void parse(queue<Token>& tokens, string _name);
        string translate(int& tabs);
};

#endif // STRUCT_H
