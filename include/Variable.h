#ifndef VARIABLE_H
#define VARIABLE_H
#include "Helper.h"

class Variable
{
    public:
        string name;
        Variable();
        void parse(deque<Token>& tokens);
        string translate();
        void changeName(string prefix);
};

#endif // VARIABLE_H
