#ifndef PROGRAM_H
#define PROGRAM_H
#include "Helper.h"
#include "Fun.h"
#include "Declaration.h"
#include "Struct.h"
#include "Define.h"
class Program
{
    public:
        vector<Fun> f;
        vector<Declaration> d;
        vector<Struct> s;
        vector<Define> def;
        Program();
        Program(const Program &program);
        void parse(deque<Token>& tokens);
        string translate(int& tabs, bool translateDefines);
        string inputFunction(int& tabs);
        void changeLocalVariablesName();
};

#endif // PROGRAM_H
