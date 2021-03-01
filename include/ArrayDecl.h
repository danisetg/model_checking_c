#ifndef ARRAYDECL_H
#define ARRAYDECL_H
#include <string>
#include <vector>
using std::string;
using std::vector;
class ArrayDecl
{
    public:
        string name;
        string functionName;
        vector<int> dimensions;
        ArrayDecl();
};

#endif // ARRAYDECL_H

