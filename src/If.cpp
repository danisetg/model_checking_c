#include "If.h"
#include "Helper.h"
If::If()
{
    //ctor
}

void If::parse(queue<Token>& tokens) {

    Token token = tokens.front();
    cout<<token.word<<endl;

    if(token.type != "IF_KEYWORD")
        mad("not an if statement");

    tokens.pop();
    token = tokens.front();

    if(token.type != "OPEN_PARENTHESIS")
        mad("Missing '('");

    tokens.pop();

    Expression _condition;
    _condition.parse(tokens);
    condition = _condition;

    token = tokens.front();
    cout<<token.word<<endl;
    if(token.type != "CLOSE_PARENTHESIS")
        mad("Missing ')'");

    tokens.pop();

    Statement _ifBody;
    _ifBody.parse(tokens);
    ifBody = _ifBody;

    token = tokens.front();
    cout<<token.word<<endl;
    if(token.type == "ELSE_KEYWORD") {
        tokens.pop();
        Statement _elseBody;
        _elseBody.parse(tokens);
        elseBody = _elseBody;
    }
}

string If::translate(string fun_name, int& tabs) {
    string code = printTabs(tabs) + "if\n";
    tabs++;
    code += printTabs(tabs) + "::" + condition.translate(tabs) + " ->\n";
    tabs++;
    code += ifBody.translate(fun_name, tabs) + "\n";
    tabs--;
    if(elseBody.has_value()) {
        code += printTabs(tabs) + "::else ->\n";
        tabs++;
        code += elseBody->translate(fun_name, tabs) + "\n";
        tabs--;
    }
    tabs--;
    code += printTabs(tabs) + "fi;\n";
    return code;
}
