#include "Fun.h"
#include <string>
#include "Helper.h"
#include "Return.h"
#include "Declaration.h"
Fun::Fun()
{
}

void Fun::parse(queue<Token>& tokens) {
    if(tokens.empty())
        mad("Function is Empty");

    Token token = tokens.front();

    if(token.type != "INT_KEYWORD")
        mad("Unknown function type");

    tokens.pop();

    token = tokens.front();

    if(token.type != "IDENTIFIER")
        mad("Missing function identifier");

    name = token.word;

    tokens.pop();

    token = tokens.front();

    if(token.type != "OPEN_PARENTHESIS")
        mad("Expected '(' after function name");

    tokens.pop();

    token = tokens.front();

    if(token.type != "CLOSE_PARENTHESIS")
        mad("Expected ')' after function arguments");

    tokens.pop();

    token = tokens.front();

    if(token.type != "OPEN_BRACE")
        mad("Expected '{' after function declaration");

    tokens.pop();

    while(!tokens.empty() && tokens.front().type != "CLOSE_BRACE") {
        Statement statement;
        statement.parse(tokens);
        if(statement.type == DECLARATION) {
            statements.insert(statements.begin(), statement);
            if(statement.decl->expression.has_value()) {
                Statement _statement;
                _statement.type = EXPRESSION;
                _statement.expression = new Expression();
                *_statement.expression = statement.decl->expression.value();
                statements.push_back(_statement);
            }

        } else
            statements.push_back(statement);
    }

    if(tokens.empty())
        mad("Expected '}' after function declaration");

    token = tokens.front();

    if(token.type != "CLOSE_BRACE")
        mad("Expected '}' after function declaration");

    tokens.pop();
}



string Fun::translate(int& tabs) {
    string code = printTabs(tabs) + "proctype " + name + "(" + "chan in_" + name + "){\n";
    tabs++;
    for(int i = 0; i < statements.size(); i++) {
        code += statements[i].translate(name, tabs) + '\n';
    }
    code += printTabs(tabs) + "end: printf(\"End of " + name + "\");\n";
    tabs--;
    code += printTabs(tabs) + "}";
    return code;
}
