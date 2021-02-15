#include "While.h"
#include "Declaration.h"

While::While()
{
    //ctor
}

void While::parse(queue<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls) {

    Token token = tokens.front();
    cout<<token.type<<endl;
    if(token.type != "WHILE_KEYWORD")
        mad("not a while statement");

    tokens.pop();
    token = tokens.front();
    cout<<token.type<<endl;
    if(token.type != "OPEN_PARENTHESIS")
        mad("Missing '('");

    tokens.pop();

    token = tokens.front();
    cout<<token.type<<endl;

    Expression _endCondition;
    _endCondition.parse(tokens, _funCalls);
    endCondition = _endCondition;

    token = tokens.front();
    cout<<token.type<<endl;

    if(token.type != "CLOSE_PARENTHESIS")
        mad("Missing ')'");

    tokens.pop();

    token = tokens.front();
    if(token.type == "OPEN_BRACE") {
        tokens.pop();
        token = tokens.front();
        while(token.type != "CLOSE_BRACE" && !tokens.empty()) {
            Statement _whileBody;
            _whileBody.parse(tokens, statements, _funCalls);
             if(_whileBody.type == DECLARATION) {
                statements.insert(statements.begin(), _whileBody);
                if(_whileBody.decl->expression.has_value()) {
                    Statement _statement;
                    _statement.type = EXPRESSION;
                    _statement.expression = new Expression();
                    *_statement.expression = _whileBody.decl->expression.value();
                    _whileBody = _statement;
                }

            }
            whileBody.push_back(_whileBody);
            token = tokens.front();
        }
        if(token.type != "CLOSE_BRACE")
            mad("missing '}'");
        tokens.pop();
    } else {
        Statement _whileBody;
        if(_whileBody.type == DECLARATION) {
                statements.insert(statements.begin(), _whileBody);
                if(_whileBody.decl->expression.has_value()) {
                    Statement _statement;
                    _statement.type = EXPRESSION;
                    _statement.expression = new Expression();
                    *_statement.expression = _whileBody.decl->expression.value();
                    _whileBody = _statement;
                }

        }
        _whileBody.parse(tokens, statements, _funCalls);
        whileBody.push_back(_whileBody);
    }
}

string While::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string code = "";
    code += printTabs(tabs) + "do\n";
    tabs++;

    code += printTabs(tabs) + "::!" + endCondition.translate(fun_name, tabs, funCallNumber, previousCode) + " -> break;\n";

    code += printTabs(tabs) + "::else ->\n";
    tabs++;

    for(int i = 0; i < whileBody.size(); i++) {
        code += whileBody[i].translate(fun_name, tabs, funCallNumber, previousCode) + "\n";
    }
    tabs--;
    tabs--;
    code += printTabs(tabs) + "od";
    return code;
}
