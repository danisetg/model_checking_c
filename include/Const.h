#ifndef CONST_H
#define CONST_H
#include "Helper.h"
class Const
{
    public:
        string value;
        Const();
        Const(string _value);
        void parse(deque<Token>& tokens);
        string translate();

};

#endif // CONST_H
