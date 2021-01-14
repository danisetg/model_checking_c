#ifndef PROGRAM_H
#define PROGRAM_H
#include "Fun.h"

class Program
{
    public:
        Fun f;
        Program();
        Program(Fun &_f);
        void parse(queue<Token>& tokens);
        string translate(int& tabs);
};

#endif // PROGRAM_H
