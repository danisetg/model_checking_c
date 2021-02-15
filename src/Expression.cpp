#include "Expression.h"
#include "Const.h"
#include "Helper.h"
#include "UnaryOperator.h"
#include "BinaryOperator.h"
#include "Variable.h"
#include "Assignment.h"
#include "Conditional.h"
#include "FunCall.h"
Expression::Expression()
{
}
Expression Expression::parseFactor (queue<Token>& tokens, vector<string>& _funCalls) {
    if(tokens.empty())
        mad("Missing factor expression");
    Expression exp;
    Token token = tokens.front();
    if(token.type == "OPEN_PARENTHESIS") {
        tokens.pop();
        exp = parseAssignment(tokens, _funCalls);
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
        _unaryOperator.parse(tokens, _funCalls);
        exp.type = UNARY_OPERATOR;
        exp.unaryOperator = new UnaryOperator();
        *exp.unaryOperator = _unaryOperator;
    } else if(token.type == "IDENTIFIER") {
        Variable _var;
        _var.parse(tokens);
        token = tokens.front();
        if(token.type == "OPEN_PARENTHESIS") {
            FunCall _funCall;
            _funCall.parse(_var.name, tokens, _funCalls);
            exp.type = FUN_CALL;
            exp.funCall = new FunCall();
            *exp.funCall = _funCall;
            _funCalls.push_back(_var.name);
        } else {
            exp.type = VARIABLE;
            exp.variable = new Variable();
            *exp.variable = _var;
        }

    }else {
        mad("Incorrect expression structure");
    }
    return exp;
}

Expression Expression::parseTerm(queue<Token>& tokens, vector<string>& _funCalls) {
    if(tokens.empty())
        mad("Missing expression");

    Expression factor = parseFactor(tokens, _funCalls);
    Token token = tokens.front();
    while(token.type == "MULTIPLICATION" || token.type == "DIVISION" || token.type == "MOD") {
        tokens.pop();
        Expression factor1 = factor;
        Expression factor2 = parseFactor(tokens, _funCalls);
        factor.type = BINARY_OPERATOR;
        BinaryOperator _binaryOperator = BinaryOperator(token.word, factor1, factor2);
        factor.binaryOperator = new BinaryOperator();
        *factor.binaryOperator = _binaryOperator;
        token = tokens.front();
    }

    return factor;
}

Expression Expression::parseAddition(queue<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression term = parseTerm(tokens, _funCalls);
    Token token = tokens.front();

    while(token.type == "NEGATION" || token.type == "ADDITION") {
        tokens.pop();
        Expression term1 = term;
        Expression term2 = parseTerm(tokens, _funCalls);
        term.type = BINARY_OPERATOR;
        BinaryOperator _binaryOperator = BinaryOperator(token.word, term1, term2);
        term.binaryOperator = new BinaryOperator();
        *term.binaryOperator = _binaryOperator;
        token = tokens.front();
    }
    return term;
}

Expression Expression::parseRelationalInequalities(queue<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression add = parseAddition(tokens, _funCalls);
    Token token = tokens.front();

    while(token.type == "LESS_OR_EQUAL_TO" || token.type == "LESS_THAN" || token.type == "GREATER_OR_EQUAL_TO" || token.type == "GREATER_THAN") {
        tokens.pop();
        Expression add1 = add;
        Expression add2 = parseAddition(tokens, _funCalls);
        add.type = BINARY_OPERATOR;
        BinaryOperator _binaryOperator = BinaryOperator(token.word, add1, add2);
        add.binaryOperator = new BinaryOperator();
        *add.binaryOperator = _binaryOperator;
        token = tokens.front();
    }
    return add;
}

Expression Expression::parseRelationalEqualities(queue<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression rel = parseRelationalInequalities(tokens, _funCalls);
    Token token = tokens.front();

    while(token.type == "EQUAL_TO" || token.type == "NOT_EQUAL_TO") {
        tokens.pop();
        Expression rel1 = rel;
        Expression rel2 = parseRelationalInequalities(tokens, _funCalls);
        rel.type = BINARY_OPERATOR;
        BinaryOperator _binaryOperator = BinaryOperator(token.word, rel1, rel2);
        rel.binaryOperator = new BinaryOperator();
        *rel.binaryOperator = _binaryOperator;
        token = tokens.front();
    }
    return rel;
}

Expression Expression::parseAnd(queue<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression rel = parseRelationalEqualities(tokens, _funCalls);
    Token token = tokens.front();

    while(token.type == "LOGICAL_AND") {
        tokens.pop();
        Expression rel1 = rel;
        Expression rel2 = parseRelationalEqualities(tokens, _funCalls);
        rel.type = BINARY_OPERATOR;
        BinaryOperator _binaryOperator = BinaryOperator(token.word, rel1, rel2);
        rel.binaryOperator = new BinaryOperator();
        *rel.binaryOperator = _binaryOperator;
        token = tokens.front();
    }
    return rel;
}

Expression Expression::parseOr(queue<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression logical = parseAnd(tokens, _funCalls);
    Token token = tokens.front();
    while(token.type == "LOGICAL_OR") {
        cout<<token.word<<endl;
        tokens.pop();
        Expression logical1 = logical;
        Expression logical2 = parseAnd(tokens, _funCalls);
        logical.type = BINARY_OPERATOR;
        BinaryOperator _binaryOperator = BinaryOperator(token.word, logical1, logical2);
        logical.binaryOperator = new BinaryOperator();
        *logical.binaryOperator = _binaryOperator;
        token = tokens.front();
    }
    return logical;
}

Expression Expression::parseConditional(queue<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression logical = parseOr(tokens, _funCalls);
    Token token = tokens.front();
    while(token.type == "QUESTION_MARK") {
        tokens.pop();
        Expression e1 = logical;
        Expression e2 = parseAssignment(tokens, _funCalls);

        token = tokens.front();
        if(token.type != "COLON")
            mad("Incorrect conditional structure, expected ':'");

        tokens.pop();

        Expression e3 = parseConditional(tokens, _funCalls);

        logical.type = CONDITIONAL;

        Conditional _cond = Conditional(e1, e2, e3);
        logical.cond = new Conditional();
        *logical.cond = _cond;
        token = tokens.front();
    }
    return logical;
}

Expression Expression::parseAssignment(queue<Token>& tokens, vector<string>& _funCalls) {
    if(tokens.empty())
        mad("Expression is empty");

    Expression logical = parseConditional(tokens, _funCalls);
    Token token = tokens.front();
    if(token.type == "ASSIGNMENT") {
        if(logical.type != VARIABLE)
            mad("Left part of assignment must be a variable");
        tokens.pop();
        Variable _variable = *logical.variable;
        Expression logical2 = parseAssignment(tokens, _funCalls);
        logical.type = ASSIGNMENT;
        Assignment _assignment = Assignment(_variable, logical2);
        logical.assignment = new Assignment();
        *logical.assignment = _assignment;
    }
    return logical;
}

void Expression::parse(queue<Token>& tokens, vector<string>& _funCalls) {
    *this = parseAssignment(tokens, _funCalls);
}

string Expression::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    switch(type) {
        case CONSTANT:
            return constant->translate();
            break;
        case UNARY_OPERATOR:
            return "(" + unaryOperator->translate(fun_name, tabs, funCallNumber, previousCode) + ")";
            break;
        case BINARY_OPERATOR:
            return "(" + binaryOperator->translate(fun_name, tabs, funCallNumber, previousCode) + ")";
            break;
        case ASSIGNMENT:
            return assignment->translate(fun_name, tabs, funCallNumber, previousCode);
            break;
        case VARIABLE:
            return variable->translate();
            break;
        case CONDITIONAL:
            return cond->translate(fun_name, tabs, funCallNumber, previousCode);
            break;
        case FUN_CALL:
            return funCall->translate(fun_name, tabs, funCallNumber, previousCode);
            break;
    }
}
