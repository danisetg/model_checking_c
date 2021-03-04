#include "Statement.h"
#include "Return.h"
#include "Declaration.h"
#include "If.h"
#include "For.h"
#include "While.h"
#include "DoWhile.h"
#include "Break.h"
#include "Continue.h"
Statement::Statement()
{
    //ctor
}

void Statement::parse(queue<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls) {
    if(tokens.empty())
        mad("Statement is Empty");

    Token token = tokens.front();
    cout<<token.word<<endl;
    if(token.type == "RETURN_KEYWORD") {
        Return _ret;
        _ret.parse(tokens, _funCalls);
        ret = new Return();
        *ret = _ret;
        type = RETURN;
    } else if(token.type == "INT_KEYWORD" || token.type == "STRUCT_KEYWORD") {
        tokens.pop();
        string _type = token.type;
        token = tokens.front();
        tokens.pop();
        Declaration _decl;
        _decl.parse(tokens, _funCalls, _type, token.word);
        cout<<_type<<" "<<token.word<<endl;
        decl = new Declaration();
        *decl = _decl;
        type = DECLARATION;
    } else if(token.type == "IDENTIFIER" || token.type == "INTEGER") {
        Expression _exp;
        _exp.parse(tokens, _funCalls);
        expression = new Expression;
        *expression = _exp;
        type = EXPRESSION;
    } else if(token.type == "IF_KEYWORD") {
        If _if;
        _if.parse(tokens, statements, _funCalls);
        ifStatement = new If();
        *ifStatement = _if;
        type = IF;
    } else if(token.type == "FOR_KEYWORD"){
        For _for;
        _for.parse(tokens, statements, _funCalls);
        forStatement = new For();
        *forStatement = _for;
        type = FOR;
    } else if(token.type == "WHILE_KEYWORD"){
        While _while;
        _while.parse(tokens, statements, _funCalls);
        whileStatement = new While();
        *whileStatement = _while;
        type = WHILE;
    } else if(token.type == "DO_KEYWORD"){
        DoWhile _doWhile;
        _doWhile.parse(tokens, statements, _funCalls);
        doWhileStatement = new DoWhile();
        *doWhileStatement = _doWhile;
        type = DO_WHILE;
    }else if(token.type == "BREAK_KEYWORD") {
        type = BREAK;
        breakStatement = new Break();
        tokens.pop();
    } else if(token.type == "CONTINUE_KEYWORD") {
        type = CONTINUE;
        continueStatement = new Continue();
        tokens.pop();
    } else {
        mad("Wrong statement structure");
    }

    token = tokens.front();

    if(token.type != "SEMICOLON" && type != IF && type != FOR && type != WHILE)
        mad("Missing ';'");

    if(type != IF && type != FOR && type != WHILE)
        tokens.pop();
}

string Statement::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    cout<<type<<endl;
    switch(type) {
        case RETURN:
            return previousCode + ret->translate(fun_name, tabs, funCallNumber, previousCode);
            break;
        case DECLARATION:
            return decl->translate(tabs, false);
        case EXPRESSION:
            return previousCode + printTabs(tabs) + expression->translate(fun_name, tabs, funCallNumber, previousCode) + ";";
        case IF:
            return printTabs(tabs) + ifStatement->translate(fun_name, tabs, funCallNumber, previousCode) + ";";
        case FOR:
            return previousCode + forStatement->translate(fun_name, tabs, funCallNumber, previousCode) + ";";
        case WHILE:
            return previousCode + whileStatement->translate(fun_name, tabs, funCallNumber, previousCode) + ";";
        case  DO_WHILE:
            return previousCode + doWhileStatement->translate(fun_name, tabs, funCallNumber, previousCode) + ";";
        case BREAK:
            return printTabs(tabs) + breakStatement->translate() + ";";
        case CONTINUE:
            return printTabs(tabs) + continueStatement->translate() + ";";
    }
}
