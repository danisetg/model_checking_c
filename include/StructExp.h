#ifndef STRUCTEXP_H
#define STRUCTEXP_H
#include "Helper.h"

class StructExp
{
    public:
        string name;
        string varName;
        StructExp();
        void parse(string _name, queue<Token>& tokens);
        string translate();
};

#endif // STRUCTEXP_H
