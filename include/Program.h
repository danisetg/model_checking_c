#ifndef PROGRAM_H
#define PROGRAM_H
#include "Helper.h"
#include "Fun.h"
#include "Declaration.h"
class Program
{
    public:
        vector<Fun> f;
        vector<Declaration> d;
        Program();
        void parse(queue<Token>& tokens);
        string translate(int& tabs);
};

#endif // PROGRAM_H
