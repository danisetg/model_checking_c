#ifndef POINTERDECL_H
#define POINTERDECL_H
#include <string>

using std::string;


enum PointerType {
    INTEGER,
    STRUCTURE
};

class PointerDecl
{
    public:
        enum PointerType type;
        string name;
        PointerDecl();
};

#endif // POINTERDECL_H
