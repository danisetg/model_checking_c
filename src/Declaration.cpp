#include "Declaration.h"
#include "Assignment.h"
Declaration::Declaration()
{
    //ctor
}

void Declaration::parse (queue<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Declaration is empty");

    Token token = tokens.front();
    cout<<token.word<<endl;

    if(token.type != "INT_KEYWORD")
        mad(token.word + " is not a variable type");

    tokens.pop();

    Variable _var;
    _var.parse(tokens);

    var = _var;

    token = tokens.front();

    if(token.type == "ASSIGNMENT") {
        tokens.pop();
        Expression _exp;
        _exp.parse(tokens, _funCalls);
        Assignment assignment = Assignment(var, _exp);

        _exp.type = ASSIGNMENT;
        _exp.assignment = new Assignment();
        *_exp.assignment = assignment;

        expression = _exp;
    }
}

string Declaration::translate(int& tabs) {
    return printTabs(tabs) + "int " + var.translate() + ";";
}
