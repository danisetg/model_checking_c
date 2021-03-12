#ifndef GOTO_H
#define GOTO_H
#include "Helper.h"

class Goto
{
    public:
        string labelName;
        Goto();
        void parse(deque<Token>& tokens);
        string translate();
};

#endif // GOTO_H
