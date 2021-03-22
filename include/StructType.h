#ifndef STRUCTTYPE_H
#define STRUCTTYPE_H
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::pair;
class StructType
{
    public:
        string name;
        vector<pair<string, string> > members;
        StructType();
};

#endif // STRUCTTYPE_H
