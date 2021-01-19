#include "UnaryOperator.h"
#include "Helper.h"
#include "Expression.h"
UnaryOperator::UnaryOperator()
{
    //ctor
}

void UnaryOperator::parse (queue<Token>& tokens) {

    if(tokens.empty())
        mad("Missing unary operator");

    Token token = tokens.front();

    if(!(token.type == "NEGATION" || token.type == "BITWISE_COMPLEMENT" || token.type == "LOGICAL_NEGATION"))
        mad("Incorrect unary operator");

    op = token.word;
    tokens.pop();

    Expression _expression;

    expression = _expression.parseFactor(tokens);
}

string UnaryOperator::translate() {
    return op + expression.translate();
}
