#ifndef ATOMIC_H
#define ATOMIC_H
#include "Helper.h"
#include "Statement.h"

class Atomic
{
    public:
        vector<Statement> statements;
        Atomic();
        string translate(string fun_name,int& tabs, int& funCallNumber, string& previousCode);
};

#endif // ATOMIC_H
