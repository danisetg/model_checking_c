#include "Fun.h"
#include <string>
#include "Helper.h"

Fun::Fun()
{
}

Fun::Fun(const Fun &fun) {
    name = fun.name;
    type = fun.type;
    for(int i = 0; i < fun.statements.size(); i++) {
        Statement aux = Statement(fun.statements[i]);
        statements.push_back(aux);
    }
    parameters = fun.parameters;
    funCalls = fun.funCalls;
}

void Fun::parse(deque<Token>& tokens, string _name, string _type) {

    name = _name;
    Token token = tokens.front();



    if(token.type != "OPEN_PARENTHESIS")
        mad("Expected '(' after function name");

    tokens.pop_front();

    if(_type == "VOID_KEYWORD")
        type = VOID;
    else
        type = INTEGER;

    token = tokens.front();
    while(token.type != "CLOSE_PARENTHESIS") {
        if(token.type != "INT_KEYWORD" && token.type != "STRUCT_KEYWORD")
            mad("Unsupported parameter type");

        Declaration _decl;
        _decl.parse(tokens, funCalls);
        parameters.push_back(_decl);

        token = tokens.front();
        if(token.type != "COMMA" && token.type != "CLOSE_PARENTHESIS")
            mad("Arguments must be separated by ','");
        else if(token.type == "COMMA")
            tokens.pop_front();
        token = tokens.front();
    }


    if(token.type != "CLOSE_PARENTHESIS")
        mad("Expected ')' after function arguments");

    tokens.pop_front();

    token = tokens.front();

    if(token.type == "OPEN_BRACE") {
        tokens.pop_front();

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
            string _name = statements[i].decl->name;
            saveLocalArray(_name, statements[i].decl->dimensions, name);
        }
    }

    tokens.pop_front();
}



string Fun::translate(int& tabs) {
    chanDeclared.clear();
    if(statements.size()) {
        string code = printTabs(tabs) + "proctype " + name + "(" + "chan in_" + name;
        for(int i = 0; i < parameters.size(); i++) {
            code += "; " + parameters[i].translate(tabs, false);
        }
        code += "){\n";
        tabs++;
        if(funCalls.size()) {
            for(int i = 0; i < funCalls.size(); i++) {
                code += printTabs(tabs) + "int temp" + to_string(i) + ";\n";

                if(!chanDeclared[funCalls[i]] && funCalls[i] != "malloc" && funCalls[i] != "free") {
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
        if(type == VOID)
            code += printTabs(tabs) + "in_" + name + " ! 0;\n" + printTabs(tabs) + "goto end;\n";
        code += printTabs(tabs) + "end: printf(\"End of " + name + "\");\n";
        tabs--;
        code += printTabs(tabs) + "}";
        return code;
    }
    return "";

}

void Fun::changeVariablesName() {
    for(int i = 0; i < statements.size(); i++) {
        statements[i].changeVariablesName(name);
    }
}
