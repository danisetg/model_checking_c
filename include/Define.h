#ifndef DEFINE_H
#define DEFINE_H
#include "Expression.h"

class Define
{
    public:
        string name;
        Expression exp;
        string ifLabel;
        int dn;
        Define();
        string translate();
};

#endif // DEFINE_H
