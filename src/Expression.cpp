#include "Expression.h"
#include "Const.h"
#include "Helper.h"
#include "UnaryOperator.h"
#include "BinaryOperator.h"

Expression::Expression()
{
}
Expression Expression::parseFactor (queue<Token>& tokens) {
    if(tokens.empty())
        mad("Missing factor expression");
    Expression exp;
    Token token = tokens.front();
    cout<<token.word<<endl;
    if(token.type == "OPEN_PARENTHESIS") {
        tokens.pop();
        exp = parseExpression(tokens);
        token = tokens.front();
        if(token.type != "CLOSE_PARENTHESIS")
            mad("Incorrect expression format, missing ')'");
        tokens.pop();
    }else if(token.type == "INTEGER") {
        Const _constant;
        _constant.parse(tokens);
        exp.type = CONSTANT;
        exp.constant = new Const();
        *exp.constant = _constant;
    } else if(token.type == "NEGATION" || token.type == "BITWISE_COMPLEMENT" || token.type == "LOGICAL_NEGATION") {
         UnaryOperator _unaryOperator;
        _unaryOperator.parse(tokens);
        exp.type = UNARY_OPERATOR;
        exp.unaryOperator = new UnaryOperator();
        *exp.unaryOperator = _unaryOperator;
        type = UNARY_OPERATOR;
    } else {
        mad("Missing return value");
    }
    return exp;
}

Expression Expression::parseTerm(queue<Token>& tokens) {
    if(tokens.empty())
        mad("Missing expression");

    Expression factor = parseFactor(tokens);
    Token token = tokens.front();
    while(token.type == "MULTIPLICATION" || token.type == "DIVISION") {
        cout<<token.word<<endl;
        tokens.pop();
        Expression factor1 = factor;
        Expression factor2 = parseFactor(tokens);
        factor.type = BINARY_OPERATOR;
        BinaryOperator _binaryOperator = BinaryOperator(token.word, factor1, factor2);
        factor.binaryOperator = new BinaryOperator();
        *factor.binaryOperator = _binaryOperator;
        token = tokens.front();
    }

    return factor;
}

Expression Expression::parseExpression(queue<Token>& tokens) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression term = parseTerm(tokens);
    Token token = tokens.front();

    while(token.type == "NEGATION" || token.type == "ADDITION") {
        cout<<token.word<<endl;
        tokens.pop();
        Expression term1 = term;
        Expression term2 = parseTerm(tokens);
        term.type = BINARY_OPERATOR;
        BinaryOperator _binaryOperator = BinaryOperator(token.word, term1, term2);
        term.binaryOperator = new BinaryOperator();
        *term.binaryOperator = _binaryOperator;
        token = tokens.front();
    }
    return term;
}

void Expression::parse(queue<Token>& tokens) {
    *this = parseExpression(tokens);
}

string Expression::translate() {
    cout<<type<<endl;
    switch(type) {
        case CONSTANT:
            return constant->translate();
            break;
        case UNARY_OPERATOR:
            return "(" + unaryOperator->translate() + ")";
            break;
        case BINARY_OPERATOR:
            return "(" + binaryOperator->translate() + ")";
    }
}
