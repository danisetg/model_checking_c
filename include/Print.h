#ifndef PRINT_H
#define PRINT_H
#include "Helper.h"

class Print
{
    public:
        string message;
        Print();
        void parse(deque<Token>& tokens);
        string translate(int& tabs);
};

#endif // PRINT_H
