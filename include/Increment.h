#ifndef INCREMENT_H
#define INCREMENT_H
#include "Helper.h"
#include "Variable.h"

class Increment
{
    public:
        Variable var;
        Increment();
        void parse(deque<Token>& tokens);
        string translate();
};

#endif // INCREMENT_H
