#ifndef PROGRAM_H
#define PROGRAM_H
#include "Helper.h"
#include "Fun.h"
#include "Declaration.h"
#include "Struct.h"
class Program
{
    public:
        vector<Fun> f;
        vector<Declaration> d;
        vector<Struct> s;
        Program();
        void parse(deque<Token>& tokens);
        string translate(int& tabs);
};

#endif // PROGRAM_H
