#include "Atomic.h"

Atomic::Atomic()
{
    //ctor
}

string Atomic::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string code = "atomic{\n";
    tabs++;
    for(int i = 0; i < statements.size(); i++) {
        cout<<statements[i].type<<endl;
        code += statements[i].translate(fun_name, tabs, funCallNumber, previousCode) + "\n";
    }
    tabs--;
    code += printTabs(tabs) + "}\n";
    return code;
}
