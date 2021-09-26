#include "Define.h"

Define::Define()
{
    //ctor
}
string Define::translate() {
    int tabs = 0;
    string prev = "";
    return "#define " + name  + " " + exp.translate("", tabs, tabs, prev) + "\n";
}
