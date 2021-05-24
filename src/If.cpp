#include "If.h"
#include "Helper.h"
#include "Declaration.h"
#include "BinaryOperator.h"
If::If()
{
    //ctor
}

void If::parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls) {

    Token token = tokens.front();

    if(token.type != "IF_KEYWORD")
        mad("not an if statement");

    tokens.pop_front();
    token = tokens.front();

    if(token.type != "OPEN_PARENTHESIS")
        mad("Missing '('");

    tokens.pop_front();

    Expression _condition;
    _condition.parse(tokens, _funCalls);
    condition = _condition;

    token = tokens.front();
    if(token.type != "CLOSE_PARENTHESIS")
        mad("Missing ')'");

    tokens.pop_front();

    token = tokens.front();

    if(token.type == "OPEN_BRACE") {
        tokens.pop_front();
        token = tokens.front();
        while(token.type != "CLOSE_BRACE" && !tokens.empty()) {
            Statement _ifBody;
            _ifBody.parse(tokens, statements, _funCalls);
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
        tokens.pop_front();
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
        _ifBody.parse(tokens, statements, _funCalls);
        ifBody.push_back(_ifBody);
    }


    token = tokens.front();
    if(token.type == "ELSE_KEYWORD") {
        tokens.pop_front();
        token = tokens.front();
        if(token.type == "OPEN_BRACE") {
            tokens.pop_front();
            token = tokens.front();
            while(token.type != "CLOSE_BRACE" && !tokens.empty()) {
                Statement _elseBody;
                _elseBody.parse(tokens, statements, _funCalls);
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
            tokens.pop_front();
        } else {
            Statement _elseBody;
            _elseBody.parse(tokens, statements, _funCalls);
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

string If::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string code = "if\n";
    tabs++;
    if(condition.type == BINARY_OPERATOR) {
        cout<<condition.binaryOperator->op<<" "<<condition.binaryOperator->exp1.type<<" "<<condition.binaryOperator->exp2.type<<endl;
    }
    code += printTabs(tabs) + "::" + condition.translate(fun_name, tabs, funCallNumber, previousCode) + " ->\n";
    tabs++;
    for(int i = 0; i < ifBody.size(); i++) {
        code += ifBody[i].translate(fun_name, tabs, funCallNumber, previousCode) + "\n";
    }
    tabs--;
    if(elseBody.size()) {
        code += printTabs(tabs) + "::else ->\n";
        tabs++;
        for(int i = 0; i < elseBody.size(); i++) {
            code += elseBody[i].translate(fun_name, tabs, funCallNumber, previousCode) + "\n";
        }
        tabs--;
    } else {
        code += printTabs(tabs) + "::else -> skip;\n";
    }
    tabs--;
    code += printTabs(tabs) + "fi";
    return code;
}

void If::changeVariablesName(string prefix) {
    condition.changeVariablesName(prefix);
     for(int i = 0; i < ifBody.size(); i++) {
        ifBody[i].changeVariablesName(prefix);
    }
    for(int i = 0; i < elseBody.size(); i++) {
        elseBody[i].changeVariablesName(prefix);
    }
}
