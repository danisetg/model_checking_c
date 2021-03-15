#include "Declaration.h"
#include "Assignment.h"
#include "IntDecl.h"
#include "StructDecl.h"
Declaration::Declaration()
{
    //ctor
}

void Declaration::parse (deque<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Declaration is empty");

    Token token = tokens.front();
    tokens.pop_front();
    string name;
    if(token.type == "INT_KEYWORD") {
        token = tokens.front();
        if(token.type == "MULTIPLICATION") {
            isPointer = true;
            tokens.pop_front();
            token = tokens.front();
            savePointer(token.word, INTEGER);
        }
        IntDecl _int;
        _int.name = token.word;
        intDecl = new IntDecl();
        *intDecl = _int;
        name = intDecl->name;
        type = INT;
    } else if(token.type == "STRUCT_KEYWORD") {
        tokens.pop_front();
        structDecl = new StructDecl();
        token = tokens.front();
        structDecl->structName = token.word;
        tokens.pop_front();
        token = tokens.front();
        structDecl->name = token.word;

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
        left.variable->name =  name;

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
            code += structDecl->translate(isPointer);
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
