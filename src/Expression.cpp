#include "Expression.h"
#include "Const.h"
#include "Helper.h"
#include "UnaryOperator.h"

Expression::Expression()
{
}
void Expression::parse (queue<Token>& tokens) {

    if(tokens.empty())
        mad("Expression is empty");

    Token token = tokens.front();

    if(token.type == "INTEGER") {
        Const _constant;
        _constant.parse(tokens);
        constant = new Const();
        *constant = _constant;
        type = CONSTANT;
    } else if(token.type == "NEGATION" || token.type == "BITWISE_COMPLEMENT" || token.type == "LOGICAL_NEGATION") {
         UnaryOperator _unaryOperator;
        _unaryOperator.parse(tokens);
        unaryOperator = new UnaryOperator();
        *unaryOperator = _unaryOperator;
        type = UNARY_OPERATOR;
    } else {
        mad("Missing return value");
    }
}
string Expression::translate() {
    switch(type) {
        case CONSTANT:
            return constant->translate();
            break;
        case UNARY_OPERATOR:
            return unaryOperator->translate();
            break;
    }
}
