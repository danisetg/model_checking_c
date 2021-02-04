#include "Conditional.h"

Conditional::Conditional()
{
    //ctor
}

Conditional::Conditional(Expression& e1, Expression& e2, Expression& e3)
{
    condition = e1;
    trueAssign = e2;
    falseAssign = e3;
}

string Conditional::translate(string fun_name, int& tabs) {
    string code = "if\n";
    tabs++;
    code += printTabs(tabs) + "::" + condition.translate(fun_name, tabs) + " ->\n";
    tabs++;
    code += printTabs(tabs) + trueAssign.translate(fun_name, tabs) + ";\n";
    tabs--;
    code += printTabs(tabs) + "::else ->\n";
    tabs++;
    code += printTabs(tabs) + falseAssign.translate(fun_name, tabs) + ";\n";
    tabs--;
    tabs--;
    code += printTabs(tabs) + "fi";
    return code;
}
