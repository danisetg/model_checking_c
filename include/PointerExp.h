#ifndef POINTEREXP_H
#define POINTEREXP_H
#include "Helper.h"
#include "Expression.h"

class PointerExp
{
    public:
        string pointerName;
        string varName;
        PointerExp();
         void parse(string name, deque<Token>& tokens);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
};

#endif // POINTEREXP_H
