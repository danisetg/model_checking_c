#include "Statement.h"
#include "Return.h"
#include "Declaration.h"
#include "If.h"
Statement::Statement()
{
    //ctor
}

void Statement::parse(queue<Token>& tokens) {
    if(tokens.empty())
        mad("Statement is Empty");

    Token token = tokens.front();
    if(token.type == "RETURN_KEYWORD") {
        Return _ret;
        _ret.parse(tokens);
        ret = new Return();
        *ret = _ret;
        type = RETURN;
    } else if(token.type == "INT_KEYWORD") {
        Declaration _decl;
        _decl.parse(tokens);
        decl = new Declaration();
        *decl = _decl;
        type = DECLARATION;
    } else if(token.type == "IDENTIFIER" || token.type == "INTEGER") {
        Expression _exp;
        _exp.parse(tokens);
        expression = new Expression;
        *expression = _exp;
        type = EXPRESSION;
    } else if(token.type == "IF_KEYWORD") {
        If _if;
        _if.parse(tokens);
        ifStatement = new If();
        *ifStatement = _if;
        type = IF;
    } else {
        mad("Wrong statement structure");
    }

    token = tokens.front();

    if(token.type != "SEMICOLON" && type != IF)
        mad("Missing ';'");

    if(type != IF)
        tokens.pop();
}

string Statement::translate(string fun_name, int& tabs) {
    switch(type) {
        case RETURN:
            return ret->translate(fun_name, tabs);
            break;
        case DECLARATION:
            return decl->translate(tabs);
        case EXPRESSION:
            return printTabs(tabs) + expression->translate(tabs) + ";";
        case IF:
            return ifStatement->translate(fun_name, tabs);
    }
}
