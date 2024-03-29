#include "For.h"
#include "Declaration.h"
For::For()
{
    //ctor
}

For::For(const For &forStatement) {
    if(forStatement.initialValue.has_value()) {
        initialValue = Statement(forStatement.initialValue.value());
    }
    if(forStatement.endCondition.has_value()) {
        endCondition = Expression(forStatement.endCondition.value());
    }
    if(forStatement.nextValue.has_value()) {
        nextValue = Expression(forStatement.nextValue.value());
    }
    for(int i = 0; i < forStatement.forBody.size(); i++) {
        forBody.push_back(Statement(forStatement.forBody[i]));
    }
}

void For::parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls) {

    Token token = tokens.front();
    if(token.type != "FOR_KEYWORD")
        mad("not a for statement");

    tokens.pop_front();
    token = tokens.front();
    if(token.type != "OPEN_PARENTHESIS")
        mad("Missing '('");

    tokens.pop_front();

    token = tokens.front();
    if(token.type != "SEMICOLON") {
        Statement _initialValue;
        _initialValue.parse(tokens, statements, _funCalls);

        if(_initialValue.type == DECLARATION) {
            statements.insert(statements.begin(), _initialValue);
            if(_initialValue.decl->expression.has_value()) {
                Statement _statement;
                _statement.type = EXPRESSION;
                _statement.expression = new Expression();
                *_statement.expression = _initialValue.decl->expression.value();
                _initialValue = _statement;
            }
        }

        initialValue = _initialValue;
    } else
        tokens.pop_front();

    token = tokens.front();

    if(token.type != "SEMICOLON") {
        Expression _endCondition;
        _endCondition.parse(tokens, _funCalls);
        endCondition = _endCondition;
    }


    token = tokens.front();
    if(token.type != "SEMICOLON")
        mad("Missing ';'");

    tokens.pop_front();

    token = tokens.front();
    if(token.type != "CLOSE_PARENTHESIS") {
        Expression _nextValue;
        _nextValue.parse(tokens, _funCalls);
        nextValue = _nextValue;
    }

    token = tokens.front();
    if(token.type != "CLOSE_PARENTHESIS")
        mad("Missing ')'");

    tokens.pop_front();

    token = tokens.front();
    if(token.type == "OPEN_BRACE") {
        tokens.pop_front();
        token = tokens.front();
        while(token.type != "CLOSE_BRACE" && !tokens.empty()) {
            Statement _forBody;
            _forBody.parse(tokens, statements, _funCalls);
             if(_forBody.type == DECLARATION) {
                statements.insert(statements.begin(), _forBody);
                if(_forBody.decl->expression.has_value()) {
                    Statement _statement;
                    _statement.type = EXPRESSION;
                    _statement.expression = new Expression();
                    *_statement.expression = _forBody.decl->expression.value();
                    _forBody = _statement;
                }

            }
            forBody.push_back(_forBody);
            token = tokens.front();
        }
        if(token.type != "CLOSE_BRACE")
            mad("missing '}'");
        tokens.pop_front();
    } else {
        Statement _forBody;
        if(_forBody.type == DECLARATION) {
                statements.insert(statements.begin(), _forBody);
                if(_forBody.decl->expression.has_value()) {
                    Statement _statement;
                    _statement.type = EXPRESSION;
                    _statement.expression = new Expression();
                    *_statement.expression = _forBody.decl->expression.value();
                    _forBody = _statement;
                }

        }
        _forBody.parse(tokens, statements, _funCalls);
        forBody.push_back(_forBody);
    }
}

string For::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string code = "";
    if(initialValue.has_value()) {
        code += initialValue->translate(fun_name, tabs, funCallNumber, previousCode) + "\n";
    }
    code += printTabs(tabs) + "do\n";
    tabs++;
    if(endCondition.has_value())
        code += printTabs(tabs) + "::!" + endCondition->translate(fun_name, tabs, funCallNumber, previousCode) + " -> break;\n";

    code += printTabs(tabs) + "::else ->\n";
    tabs++;

    for(int i = 0; i < forBody.size(); i++) {
        code += forBody[i].translate(fun_name, tabs, funCallNumber, previousCode) + "\n";
    }
    if(nextValue.has_value())
        code += printTabs(tabs) + nextValue->translate(fun_name, tabs, funCallNumber, previousCode) + ";\n";
    tabs--;
    tabs--;
    code += printTabs(tabs) + "od";
    return code;
}

void For::changeVariablesName(string prefix) {
    if(initialValue.has_value())
        initialValue->changeVariablesName(prefix);
    if(endCondition.has_value())
        endCondition->changeVariablesName(prefix);
    if(nextValue.has_value())
        nextValue->changeVariablesName(prefix);
    for(int i = 0; i < forBody.size(); i++) {
        forBody[i].changeVariablesName(prefix);
    }
}
