#include "Fun.h"
#include <string>
#include "Helper.h"
#include "Return.h"
#include "Declaration.h"
Fun::Fun()
{
}

void Fun::parse(queue<Token>& tokens, string _name) {

    name = _name;

    Token token = tokens.front();

    if(token.type != "OPEN_PARENTHESIS")
        mad("Expected '(' after function name");

    tokens.pop();

    token = tokens.front();
    while(token.type != "CLOSE_PARENTHESIS") {
        if(token.type != "INT_KEYWORD")
            mad("Unsupported parameter type");
        tokens.pop();
        token = tokens.front();
        cout<<token.type<<endl;
        Variable _var;
        _var.parse(tokens);
        parameters.push_back(_var);

        token = tokens.front();
        if(token.type != "COMMA" && token.type != "CLOSE_PARENTHESIS")
            mad("Arguments must be separated by ','");
        else if(token.type == "COMMA")
            tokens.pop();
        token = tokens.front();
    }


    if(token.type != "CLOSE_PARENTHESIS")
        mad("Expected ')' after function arguments");

    tokens.pop();

    token = tokens.front();

    if(token.type == "OPEN_BRACE") {
        tokens.pop();

        while(!tokens.empty() && tokens.front().type != "CLOSE_BRACE") {
            Statement statement;
            statement.parse(tokens, statements, funCalls);
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
    } else if(token.type != "SEMICOLON")
        mad("Fordward declarations must end with ';'");

    for(int i = 0; i < statements.size(); i++) {
        if(statements[i].type == DECLARATION && statements[i].decl->dimensions.size()) {
            saveLocalArray(statements[i].decl->var.name, statements[i].decl->dimensions, name);
        }
    }

    tokens.pop();
}



string Fun::translate(int& tabs) {
   // cout<<"    "<<name<<endl;
    if(statements.size()) {
        string code = printTabs(tabs) + "proctype " + name + "(" + "chan in_" + name;
        for(int i = 0; i < parameters.size(); i++) {
            code += "; int " + parameters[i].name;
        }
        code += "){\n";
        tabs++;
        if(funCalls.size()) {
            for(int i = 0; i < funCalls.size(); i++) {
                code += printTabs(tabs) + "int temp" + to_string(i) + ";\n";
                if(!chanDeclared[funCalls[i]]) {
                    code += printTabs(tabs) + "chan ret_" + funCalls[i] + " = [0] of { int };\n";
                    chanDeclared[funCalls[i]] = true;
                }

            }
        }
        int funCallNumber = 0;
        for(int i = 0; i < statements.size(); i++) {
            string previousCode = "";
            string tmp = statements[i].translate(name, tabs, funCallNumber, previousCode);
            code += tmp + '\n';
        }
        code += printTabs(tabs) + "end: printf(\"End of " + name + "\");\n";
        tabs--;
        code += printTabs(tabs) + "}";
        return code;
    }
    return "";

}
