#include "Switch.h"

Switch::Switch()
{
    //ctor
}

void Switch::parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls) {

    Token token = tokens.front();

    if(token.type != "SWITCH_KEYWORD")
        mad("not a switch statement");

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

    if(token.type != "OPEN_BRACE")
        mad("missing '{'");

    tokens.pop_front();
    token = tokens.front();
    while(token.type != "CLOSE_BRACE" && !tokens.empty()) {

        if(token.type == "CASE_KEYWORD") {
            tokens.pop_front();
            Expression caseExpression;
            caseExpression.parse(tokens, _funCalls);
            token = tokens.front();
            cases.push_back(caseExpression);

            if(token.type != "COLON")
                mad("Missing case ':'");

            tokens.pop_front();

            token = tokens.front();
            vector<Statement> _caseStatements;
            while(token.type != "CASE_KEYWORD" && token.type != "DEFAULT_KEYWORD" && token.type != "CLOSE_BRACE") {
                Statement statement;
                statement.parse(tokens, statements, _funCalls);
                _caseStatements.push_back(statement);
                token = tokens.front();
            }
            caseStatements.push_back(_caseStatements);

        }else if(token.type == "DEFAULT_KEYWORD") {
            tokens.pop_front();
            token = tokens.front();
            if(token.type != "COLON")
                mad("Missing default ':'");

            tokens.pop_front();

            token = tokens.front();

            while(token.type != "CASE_KEYWORD" && token.type != "DEFAULT_KEYWORD" && token.type != "CLOSE_BRACE") {
                Statement statement;
                statement.parse(tokens, statements, _funCalls);
                defaultStatements.push_back(statement);
                token = tokens.front();
            }

        } else {
            mad("Expecting 'case' or 'default' keyword");
        }
    }

    cout<<token.type<<endl;
    if(token.type != "CLOSE_BRACE")
        mad("missing '}'");



    tokens.pop_front();
}

string Switch::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string code = "if\n";
    tabs++;
    for(int i = 0; i < cases.size(); i++) {
        code += printTabs(tabs) + "::" + condition.translate(fun_name, tabs, funCallNumber, previousCode)
                + " == " + cases[i].translate(fun_name, tabs, funCallNumber, previousCode) + " ->\n";
        tabs++;
        for(int h = 0; h < caseStatements[i].size(); h++) {
            if(caseStatements[i][h].type != BREAK)
                code += caseStatements[i][h].translate(fun_name, tabs, funCallNumber, previousCode) + "\n";
        }
        tabs--;
    }
    if(defaultStatements.size()) {
        code += printTabs(tabs) + "::else ->\n";
        tabs++;
        for(int h = 0; h < defaultStatements.size(); h++) {
            if(defaultStatements[h].type != BREAK)
                code += defaultStatements[h].translate(fun_name, tabs, funCallNumber, previousCode) + "\n";
        }
        tabs--;
    }

    tabs--;
    code += printTabs(tabs) + "fi;";

    return code;
}
