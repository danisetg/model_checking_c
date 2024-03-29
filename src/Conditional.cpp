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

Conditional::Conditional(const Conditional &cond) {
    condition = Expression(cond.condition);
    trueAssign = Expression(cond.trueAssign);
    falseAssign = Expression(cond.falseAssign);
}

string Conditional::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string code = "if\n";
    tabs++;
    code += printTabs(tabs) + "::" + condition.translate(fun_name, tabs, funCallNumber, previousCode) + " ->\n";
    tabs++;
    code += printTabs(tabs) + trueAssign.translate(fun_name, tabs, funCallNumber, previousCode) + ";\n";
    tabs--;
    code += printTabs(tabs) + "::else ->\n";
    tabs++;
    code += printTabs(tabs) + falseAssign.translate(fun_name, tabs, funCallNumber, previousCode) + ";\n";
    tabs--;
    tabs--;
    code += printTabs(tabs) + "fi";
    return code;
}

void Conditional::changeVariablesName(string prefix) {
    condition.changeVariablesName(prefix);
    trueAssign.changeVariablesName(prefix);
    falseAssign.changeVariablesName(prefix);
}
