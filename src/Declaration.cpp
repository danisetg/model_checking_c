#include "Declaration.h"
#include "Assignment.h"
#include "IntDecl.h"
#include "StructDecl.h"
Declaration::Declaration()
{
    //ctor
}

void Declaration::parse (deque<Token>& tokens, vector<string>& _funCalls, string _type, string _name) {

    if(tokens.empty())
        mad("Declaration is empty");

    Token token = tokens.front();
    string name;
    cout<<_name<<" "<<_type<<endl;
    if(_type == "INT_KEYWORD") {
        IntDecl _int;
        _int.name = _name;
        intDecl = new IntDecl();
        *intDecl = _int;
        name = intDecl->name;
        type = INT;
    } else if(_type == "STRUCT_KEYWORD") {
        structDecl = new StructDecl();
        structDecl->name = token.word;
        structDecl->structName = _name;
        name = structDecl->name;
        tokens.pop_front();
        type = STRUCT;
    } else
        mad("Not a variable type");

    token = tokens.front();

    while(token.type == "OPEN_BRACKET") {
        tokens.pop_front();
        token = tokens.front();

        if(token.type != "INTEGER")
            mad("Array dimension must be constant integer quantity");

        dimensions.push_back(stoi(token.word));
        tokens.pop_front();
        token = tokens.front();
        if(token.type != "CLOSE_BRACKET")
            mad("missing ']'");

        tokens.pop_front();
        token = tokens.front();
    }

    if(token.type == "ASSIGNMENT") {
        tokens.pop_front();
        Expression _exp;
        _exp.parse(tokens, _funCalls);

        Expression left;
        left.type = VARIABLE;
        left.variable = new Variable();
        left.variable->name = _name;

        Assignment assignment = Assignment(left, _exp);

        _exp.type = ASSIGNMENT;
        _exp.assignment = new Assignment();
        *_exp.assignment = assignment;

        expression = _exp;
    }
}

string Declaration::translate(int& tabs, bool addExpression) {
    string code = printTabs(tabs);
    cout<<type<<endl;
    switch(type) {
        case INT:
            code += intDecl->translate();
            break;
        case STRUCT:
            code += structDecl->translate();
            break;
    }

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
