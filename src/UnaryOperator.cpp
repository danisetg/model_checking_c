#include "UnaryOperator.h"
#include "Helper.h"
#include "Expression.h"
UnaryOperator::UnaryOperator()
{
    //ctor
}

void UnaryOperator::parse (deque<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Missing unary operator");

    Token token = tokens.front();

    if(!(token.type == "NEGATION" || token.type == "BITWISE_COMPLEMENT" || token.type == "LOGICAL_NEGATION"))
        mad("Incorrect unary operator");

    op = token.word;
    tokens.pop_front();

    Expression _expression;

    expression = _expression.parseFactor(tokens, _funCalls);
}

string UnaryOperator::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    return op + expression.translate(fun_name, tabs, funCallNumber, previousCode);
}

void UnaryOperator::changeVariablesName(string prefix) {
    expression.changeVariablesName(prefix);
}
