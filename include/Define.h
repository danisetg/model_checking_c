#ifndef DEFINE_H
#define DEFINE_H
#include "Expression.h"

class Define
{
    public:
        string name;
        Expression exp;
        Define();
        string translate();
};

#endif // DEFINE_H
