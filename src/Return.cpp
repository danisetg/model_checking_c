#include "Return.h"
#include "Expression.h"
#include "Helper.h"
#include "UnaryOperator.h"
Return::Return()
{
}

void Return::parse(queue<Token>& tokens) {

    if(tokens.empty())
        mad("Statement is Empty");

    Token token = tokens.front();
    cout<<token.word<<endl;
    if(token.type != "RETURN_KEYWORD")
        mad("Missing function return");

    tokens.pop();

    Expression _expression;

    _expression.parse(tokens);
    expression = _expression;
}
string Return::translate(string fun_name, int& tabs) {
    string code = printTabs(tabs) + "in_" + fun_name + " ! " + expression.translate(tabs) + ";" + '\n';
    code += printTabs(tabs) + "goto end;";
    return code;
}

