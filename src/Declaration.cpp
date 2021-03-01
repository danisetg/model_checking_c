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

    while(token.type == "OPEN_BRACKET") {
        tokens.pop();
        token = tokens.front();

        if(token.type != "INTEGER")
            mad("Array dimension must be constant integer quantity");

        dimensions.push_back(stoi(token.word));
        tokens.pop();
        token = tokens.front();
        if(token.type != "CLOSE_BRACKET")
            mad("missing ']'");

        tokens.pop();
        token = tokens.front();
    }

    if(token.type == "ASSIGNMENT") {
        tokens.pop();
        Expression _exp;
        _exp.parse(tokens, _funCalls);

        Expression left;
        left.type = VARIABLE;
        left.variable = new Variable();
        *left.variable = var;

        Assignment assignment = Assignment(left, _exp);

        _exp.type = ASSIGNMENT;
        _exp.assignment = new Assignment();
        *_exp.assignment = assignment;

        expression = _exp;
    }
}

string Declaration::translate(int& tabs, bool addExpression) {
    string code = printTabs(tabs) + "int " + var.translate();

    if(dimensions.size()) {
        int dim = 1;
        for(int i = 0; i < dimensions.size(); i++) {
            dim *= dimensions[i];
        }
        code += "[" + to_string(dim) + "]";
    }

    if(addExpression && expression.has_value()) {
        string tmp = "";
        int aux = 0;
        code += " = " + expression->translate(tmp, tabs, aux, tmp);
    }

    return code + ";";
}
