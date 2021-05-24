#include "Statement.h"
#include "Return.h"
#include "Declaration.h"
#include "If.h"
#include "For.h"
#include "While.h"
#include "DoWhile.h"
#include "Break.h"
#include "Continue.h"
#include "LabeledStatement.h"
#include "Goto.h"
#include "Switch.h"
#include "Print.h"
#include "Scan.h"
#include "Atomic.h"
Statement::Statement()
{
    //ctor
}

void Statement::parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls) {
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
    } else if(token.type == "INT_KEYWORD" || token.type == "STRUCT_KEYWORD" || token.type == "BOOL_KEYWORD") {
        Declaration _decl;
        _decl.parse(tokens, _funCalls);
        decl = new Declaration();
        *decl = _decl;
        type = DECLARATION;

        while(tokens.front().type == "COMMA") {
            tokens.pop_front();
            if(token.type == "STRUCT_KEYWORD") {
                Token tmp = Token("IDENTIFIER", regex("[a-zA-Z]\\w*"), _decl.structDecl->structName);
                tokens.push_front(tmp);
            }
            tokens.push_front(token);

            Declaration _decl1;
            _decl1.parse(tokens, _funCalls);
            Statement _statement;
            _statement.type = DECLARATION;
            _statement.decl = new Declaration();
            *_statement.decl = _decl1;
            statements.insert(statements.begin(), _statement);
        }
    } else if(token.type == "PRINTF_KEYWORD") {
        Print _print;
        _print.parse(tokens);
        print = new Print();
        *print = _print;
        type = PRINT;
    } else if(token.type == "SCANF_KEYWORD") {
        Scan _scan;
        _scan.parse(tokens);
        scan = new Scan();
        *scan = _scan;
        type = SCAN;
        _funCalls.push_back("input");
        cout<<"    input"<<endl;
    } else if(token.type == "IDENTIFIER" || token.type == "INTEGER" || token.type == "MULTIPLICATION") {
        tokens.pop_front();
        Token token1 = tokens.front();
        tokens.push_front(token);
        if(token.type == "IDENTIFIER" && token1.type == "COLON") {
            LabeledStatement _label;
            _label.parse(tokens, statements, _funCalls);
            labeledStatement = new LabeledStatement();
            *labeledStatement = _label;
            type = LABELED_STATEMENT;
        } else {
            Expression _exp;
            _exp.parse(tokens, _funCalls);
            expression = new Expression;
            *expression = _exp;
            type = EXPRESSION;
        }
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
    }else if(token.type == "SWITCH_KEYWORD"){
        Switch _switch;
        _switch.parse(tokens, statements, _funCalls);
        switchStatement = new Switch();
        *switchStatement = _switch;
        type = SWITCH;
    }else if(token.type == "BREAK_KEYWORD") {
        type = BREAK;
        breakStatement = new Break();
        tokens.pop_front();
    }  else if(token.type == "CONTINUE_KEYWORD") {
        type = CONTINUE;
        continueStatement = new Continue();
        tokens.pop_front();
    } else if(token.type == "GOTO_KEYWORD") {
        type = GOTO;
        Goto _gto;
        _gto.parse(tokens);
        gto = new Goto();
        *gto = _gto;
    }else {
        mad("Wrong statement structure");
    }

    token = tokens.front();

    if(token.type != "SEMICOLON" && type != IF && type != FOR && type != WHILE && type != LABELED_STATEMENT && type != SWITCH)
        mad("Missing ';'");

    if(type != IF && type != FOR && type != WHILE && type != LABELED_STATEMENT && type != SWITCH)
        tokens.pop_front();
}

string Statement::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    switch(type) {
        case RETURN:
            return previousCode + ret->translate(fun_name, tabs, funCallNumber, previousCode);
            break;
        case DECLARATION:
            return decl->translate(tabs, false) + ";";
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
        case PRINT:
            return print->translate(tabs);
        case SCAN:
            return scan->translate(tabs);
        case CONTINUE:
            return printTabs(tabs) + continueStatement->translate() + ";";
        case LABELED_STATEMENT:
            return printTabs(tabs) + labeledStatement->translate(fun_name, tabs, funCallNumber, previousCode);
        case GOTO:
            return printTabs(tabs) + gto->translate() + ";";
        case SWITCH:
            return printTabs(tabs) + switchStatement->translate(fun_name, tabs, funCallNumber, previousCode);
         case ATOMIC:
            return printTabs(tabs) + atomic->translate(fun_name, tabs, funCallNumber, previousCode);
    }
}

void Statement::changeVariablesName(string prefix) {
    switch(type) {
        case RETURN:
            ret->changeVariablesName(prefix);
            break;
        case EXPRESSION:
            expression->changeVariablesName(prefix);
            break;
        case IF:
            ifStatement->changeVariablesName(prefix);
            break;
        case FOR:
            forStatement->changeVariablesName(prefix);
            break;
        case WHILE:
            whileStatement->changeVariablesName(prefix);
            break;
        case  DO_WHILE:
            doWhileStatement->changeVariablesName(prefix);
            break;
        case SCAN:
            scan->changeVariablesName(prefix);
            break;
        case PRINT:
            print->changeVariablesName(prefix);
            break;
        case LABELED_STATEMENT:
            labeledStatement->changeVariablesName(prefix);
            break;
        case SWITCH:
            switchStatement->changeVariablesName(prefix);
            break;
    }
}
