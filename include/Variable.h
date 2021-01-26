#ifndef VARIABLE_H
#define VARIABLE_H
#include "Helper.h"

class Variable
{
    public:
        string name;
        Variable();
        void parse(queue<Token>& tokens);
        string translate();
};

#endif // VARIABLE_H
