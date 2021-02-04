#include "If.h"
#include "Helper.h"
#include "Declaration.h"
If::If()
{
    //ctor
}

void If::parse(queue<Token>& tokens, vector<Statement>& statements) {

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

    token = tokens.front();

    if(token.type == "OPEN_BRACE") {
        tokens.pop();
        token = tokens.front();
        while(token.type != "CLOSE_BRACE" && !tokens.empty()) {
            Statement _ifBody;
            _ifBody.parse(tokens, statements);
             if(_ifBody.type == DECLARATION) {
                statements.insert(statements.begin(), _ifBody);
                if(_ifBody.decl->expression.has_value()) {
                    Statement _statement;
                    _statement.type = EXPRESSION;
                    _statement.expression = new Expression();
                    *_statement.expression = _ifBody.decl->expression.value();
                    _ifBody = _statement;
                }

            }
            ifBody.push_back(_ifBody);
            token = tokens.front();
        }
        if(token.type != "CLOSE_BRACE")
            mad("missing '}'");
        tokens.pop();
    } else {
        Statement _ifBody;
        if(_ifBody.type == DECLARATION) {
                statements.insert(statements.begin(), _ifBody);
                if(_ifBody.decl->expression.has_value()) {
                    Statement _statement;
                    _statement.type = EXPRESSION;
                    _statement.expression = new Expression();
                    *_statement.expression = _ifBody.decl->expression.value();
                    _ifBody = _statement;
                }

        }
        _ifBody.parse(tokens, statements);
        ifBody.push_back(_ifBody);
    }


    token = tokens.front();
    cout<<token.word<<endl;
    if(token.type == "ELSE_KEYWORD") {
        tokens.pop();
        token = tokens.front();
        if(token.type == "OPEN_BRACE") {
            tokens.pop();
            token = tokens.front();
            while(token.type != "CLOSE_BRACE" && !tokens.empty()) {
                Statement _elseBody;
                _elseBody.parse(tokens, statements);
                if(_elseBody.type == DECLARATION) {
                    statements.insert(statements.begin(), _elseBody);
                    if(_elseBody.decl->expression.has_value()) {
                        Statement _statement;
                        _statement.type = EXPRESSION;
                        _statement.expression = new Expression();
                        *_statement.expression = _elseBody.decl->expression.value();
                        _elseBody = _statement;
                    }

                }
                elseBody.push_back(_elseBody);
                token = tokens.front();
            }
            if(token.type != "CLOSE_BRACE")
                mad("missing '}'");
            tokens.pop();
        } else {
            Statement _elseBody;
            _elseBody.parse(tokens, statements);
            if(_elseBody.type == DECLARATION) {
                statements.insert(statements.begin(), _elseBody);
                if(_elseBody.decl->expression.has_value()) {
                    Statement _statement;
                    _statement.type = EXPRESSION;
                    _statement.expression = new Expression();
                    *_statement.expression = _elseBody.decl->expression.value();
                    _elseBody = _statement;
                }

            }
            elseBody.push_back(_elseBody);
        }
    }
}

string If::translate(string fun_name, int& tabs) {
    string code = "if\n";
    tabs++;
    code += printTabs(tabs) + "::" + condition.translate(fun_name, tabs) + " ->\n";
    tabs++;
    for(int i = 0; i < ifBody.size(); i++) {
        code += ifBody[i].translate(fun_name, tabs) + "\n";
    }
    tabs--;
    if(elseBody.size()) {
        code += printTabs(tabs) + "::else ->\n";
        tabs++;
        for(int i = 0; i < elseBody.size(); i++) {
            code += elseBody[i].translate(fun_name, tabs) + "\n";
        }
        tabs--;
    }
    tabs--;
    code += printTabs(tabs) + "fi";
    return code;
}
