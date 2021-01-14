#include "Fun.h"
#include <string>
#include "Helper.h"
using std::string;
using std::cout;
using std::endl;
Fun::Fun(string _name, Return &_statement)
{
    name = _name;
    statement = _statement;
}
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

    Return _statement;
    _statement.parse(tokens);


    statement = _statement;

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
    code += statement.translate(name, tabs) + '\n';
    code += printTabs(tabs) + "end: printf(\"End of " + name + "\");\n";
    tabs--;
    code += printTabs(tabs) + "}";
    return code;
}
