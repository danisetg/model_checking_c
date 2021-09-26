#include "DoWhile.h"
#include "Declaration.h"

DoWhile::DoWhile()
{
    //ctor
}
DoWhile::DoWhile(const DoWhile &doWhile) {
    endCondition = Expression(doWhile.endCondition);
    for(int i = 0; i < doWhile.body.size(); i++) {
        body.push_back(Statement(doWhile.body[i]));
    }
}
void DoWhile::parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls) {

    Token token = tokens.front();
    if(token.type != "DO_KEYWORD")
        mad("not a do while statement");

    tokens.pop_front();

    token = tokens.front();
    if(token.type == "OPEN_BRACE") {
        tokens.pop_front();
        token = tokens.front();
        while(token.type != "CLOSE_BRACE" && !tokens.empty()) {
            Statement _doWhileBody;
            _doWhileBody.parse(tokens, statements, _funCalls);
             if(_doWhileBody.type == DECLARATION) {
                statements.insert(statements.begin(), _doWhileBody);
                if(_doWhileBody.decl->expression.has_value()) {
                    Statement _statement;
                    _statement.type = EXPRESSION;
                    _statement.expression = new Expression();
                    *_statement.expression = _doWhileBody.decl->expression.value();
                    _doWhileBody = _statement;
                }

            }
            body.push_back(_doWhileBody);
            token = tokens.front();
        }
        if(token.type != "CLOSE_BRACE")
            mad("missing '}'");
        tokens.pop_front();
    } else {
        Statement _doWhileBody;
        if(_doWhileBody.type == DECLARATION) {
                statements.insert(statements.begin(), _doWhileBody);
                if(_doWhileBody.decl->expression.has_value()) {
                    Statement _statement;
                    _statement.type = EXPRESSION;
                    _statement.expression = new Expression();
                    *_statement.expression = _doWhileBody.decl->expression.value();
                    _doWhileBody = _statement;
                }

        }
        _doWhileBody.parse(tokens, statements, _funCalls);
        body.push_back(_doWhileBody);
    }
    token = tokens.front();

    if(token.type != "WHILE_KEYWORD")
        mad("Missing 'while'");

    tokens.pop_front();

    token = tokens.front();

    if(token.type != "OPEN_PARENTHESIS")
        mad("Missing '('");

    tokens.pop_front();

    token = tokens.front();

    Expression _endCondition;
    _endCondition.parse(tokens, _funCalls);
    endCondition = _endCondition;

    token = tokens.front();

    if(token.type != "CLOSE_PARENTHESIS")
        mad("Missing ')'");

    tokens.pop_front();
}

string DoWhile::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string code = "";
    code += printTabs(tabs) + "do\n";
    tabs++;
    code += printTabs(tabs) + "::true ->\n";
    tabs++;

    for(int i = 0; i < body.size(); i++) {
        code += body[i].translate(fun_name, tabs, funCallNumber, previousCode) + "\n";
    }
    code += printTabs(tabs) + "if\n";
    tabs++;
    code += printTabs(tabs) + "::!" + endCondition.translate(fun_name, tabs, funCallNumber, previousCode) + " -> break;\n";
    tabs--;
    code += printTabs(tabs) + "fi;\n";
    tabs--;
    tabs--;
    code += printTabs(tabs) + "od";
    return code;
}

void DoWhile::changeVariablesName(string prefix) {
    endCondition.changeVariablesName(prefix);
    for(int i = 0; i < body.size(); i++) {
        body[i].changeVariablesName(prefix);
    }
}
