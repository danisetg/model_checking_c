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
        exp = parseOr(tokens);
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

Expression Expression::parseAddition(queue<Token>& tokens) {

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

Expression Expression::parseRelationalInequalities(queue<Token>& tokens) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression add = parseAddition(tokens);
    Token token = tokens.front();

    while(token.type == "LESS_OR_EQUAL_TO" || token.type == "LESS_THAN" || token.type == "GREATER_OR_EQUAL_TO" || token.type == "GREATER_THAN") {
        cout<<token.word<<endl;
        tokens.pop();
        Expression add1 = add;
        Expression add2 = parseAddition(tokens);
        add.type = BINARY_OPERATOR;
        BinaryOperator _binaryOperator = BinaryOperator(token.word, add1, add2);
        add.binaryOperator = new BinaryOperator();
        *add.binaryOperator = _binaryOperator;
        token = tokens.front();
    }
    return add;
}

Expression Expression::parseRelationalEqualities(queue<Token>& tokens) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression rel = parseRelationalInequalities(tokens);
    Token token = tokens.front();

    while(token.type == "EQUAL_TO" || token.type == "NOT_EQUAL_TO") {
        cout<<token.word<<endl;
        tokens.pop();
        Expression rel1 = rel;
        Expression rel2 = parseRelationalInequalities(tokens);
        rel.type = BINARY_OPERATOR;
        BinaryOperator _binaryOperator = BinaryOperator(token.word, rel1, rel2);
        rel.binaryOperator = new BinaryOperator();
        *rel.binaryOperator = _binaryOperator;
        token = tokens.front();
    }
    return rel;
}

Expression Expression::parseAnd(queue<Token>& tokens) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression rel = parseRelationalEqualities(tokens);
    Token token = tokens.front();

    while(token.type == "LOGICAL_AND") {
        cout<<token.word<<endl;
        tokens.pop();
        Expression rel1 = rel;
        Expression rel2 = parseRelationalEqualities(tokens);
        rel.type = BINARY_OPERATOR;
        BinaryOperator _binaryOperator = BinaryOperator(token.word, rel1, rel2);
        rel.binaryOperator = new BinaryOperator();
        *rel.binaryOperator = _binaryOperator;
        token = tokens.front();
    }
    return rel;
}

Expression Expression::parseOr(queue<Token>& tokens) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression logical = parseAnd(tokens);
    Token token = tokens.front();
    while(token.type == "LOGICAL_OR") {
        cout<<token.word<<endl;
        tokens.pop();
        Expression logical1 = logical;
        Expression logical2 = parseAnd(tokens);
        logical.type = BINARY_OPERATOR;
        BinaryOperator _binaryOperator = BinaryOperator(token.word, logical1, logical2);
        logical.binaryOperator = new BinaryOperator();
        *logical.binaryOperator = _binaryOperator;
        token = tokens.front();
    }
    return logical;
}

void Expression::parse(queue<Token>& tokens) {
    *this = parseOr(tokens);
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
