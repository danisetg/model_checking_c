#ifndef DECREMENT_H
#define DECREMENT_H
#include "Helper.h"
#include "Variable.h"

class Decrement
{
    public:
        Variable var;
        Decrement();
        void parse(deque<Token>& tokens);
        string translate();
        void changeVariablesName(string prefix);
};

#endif // DECREMENT_H
