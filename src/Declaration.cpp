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

    cout<<token.type<<endl;
    if(token.type == "INT_KEYWORD") {
        token = tokens.front();
        if(token.type == "MULTIPLICATION") {
            isPointer = true;
            tokens.pop_front();
            token = tokens.front();
            savePointer(token.word, "int");
        }
        IntDecl _int;
        name = token.word;
        intDecl = new IntDecl();
        *intDecl = _int;
        type = INT;
    }else if(token.type == "BOOL_KEYWORD") {
        token = tokens.front();
        if(token.type == "MULTIPLICATION") {
            isPointer = true;
            tokens.pop_front();
            token = tokens.front();
            savePointer(token.word, "bool");
        }
        BoolDecl _bool;
        name = token.word;
        boolDecl = new BoolDecl();
        *boolDecl = _bool;
        type = BOOL;
    } else if(token.type == "STRUCT_KEYWORD") {
        structDecl = new StructDecl();
        token = tokens.front();

        structDecl->structName = token.word;
        tokens.pop_front();
        token = tokens.front();
        if(token.type == "MULTIPLICATION") {
            isPointer = true;
            tokens.pop_front();
            token = tokens.front();
            cout<<token.word<<" "<<structDecl->structName<<endl;
            savePointer(token.word, structDecl->structName);
        }
        name = token.word;

        type = STRUCT;
    } else
        mad("Not a variable type");

    tokens.pop_front();
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
    switch(type) {
        case INT:
            code += intDecl->translate(name);
            break;
        case STRUCT:
            code += structDecl->translate(isPointer, name);
            break;
        case BOOL:
            code += boolDecl->translate(name);
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

    return code;
}
