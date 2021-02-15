#include "Return.h"
#include "Expression.h"
#include "Helper.h"
#include "UnaryOperator.h"
#include "If.h"
#include "Conditional.h"
Return::Return()
{
}

void Return::parse(queue<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Statement is Empty");

    Token token = tokens.front();
    cout<<token.word<<endl;
    if(token.type != "RETURN_KEYWORD")
        mad("Missing function return");

    tokens.pop();

    Expression _expression;

    _expression.parse(tokens, _funCalls);
    expression = _expression;
}

string Return::translateConditional(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    If ifStatement;
    ifStatement.condition = expression.cond->condition;

    Return trueReturn;
    trueReturn.expression = expression.cond->trueAssign;

    Statement trueStatement;
    trueStatement.type = RETURN;
    trueStatement.ret = new Return();
    *trueStatement.ret = trueReturn;


    Return falseReturn;
    falseReturn.expression = expression.cond->falseAssign;

    Statement falseStatement;
    falseStatement.type = RETURN;
    falseStatement.ret = new Return();
    *falseStatement.ret = falseReturn;

    ifStatement.ifBody.push_back(trueStatement);
    ifStatement.elseBody.push_back(falseStatement);

    return ifStatement.translate(fun_name, tabs, funCallNumber, previousCode);
}
string Return::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string code = "";
    if(expression.type == CONDITIONAL) {
        code = printTabs(tabs) + translateConditional(fun_name, tabs, funCallNumber, previousCode) + ";";
    } else {
        code  = printTabs(tabs) + "in_" + fun_name + " ! " + expression.translate(fun_name, tabs, funCallNumber, previousCode) + ";" + '\n';
        code += printTabs(tabs) + "goto end;";
    }
    return code;
}

