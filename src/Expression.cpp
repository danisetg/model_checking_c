#include "Expression.h"
#include "Const.h"
#include "Helper.h"
#include "UnaryOperator.h"
#include "BinaryOperator.h"
#include "Variable.h"
#include "Assignment.h"
#include "Conditional.h"
#include "FunCall.h"
#include "Array.h"
#include "StructExp.h"
#include "Increment.h"
#include "Decrement.h"
#include "PointerExp.h"
Expression::Expression()
{
}

Expression::Expression(const Expression &exp) {
    type = exp.type;
    switch(type) {
        case CONSTANT:
            constant = new Const();
            *constant = *exp.constant;
            break;
        case UNARY_OPERATOR:
            unaryOperator = new UnaryOperator(*exp.unaryOperator);
            break;
        case BINARY_OPERATOR:
            binaryOperator = new BinaryOperator(*exp.binaryOperator);
            break;
        case ASSIGNMENT:
            assignment = new Assignment(*exp.assignment);
            break;
        case VARIABLE:
            variable = new Variable();
            *variable = *exp.variable;
            break;
        case CONDITIONAL:
            cond = new Conditional(*exp.cond);
            break;
        case FUN_CALL:
            funCall = new FunCall(*exp.funCall);
            break;
        case ARRAY:
            arr = new Array(*exp.arr);
            break;
        case STRUCT_EXPRESSION:
            structExp = new StructExp();
            *structExp = *exp.structExp;
            break;
        case POINTER_EXPRESSION:
            pointerExp = new PointerExp();
            *pointerExp = *exp.pointerExp;
            break;
        case INCREMENT:
            increment = new Increment();
            *increment = *exp.increment;
            break;
        case DECREMENT:
            decrement = new Decrement();
            *decrement = *exp.decrement;
            break;
    }
}

Expression Expression::parseSubFactor(deque<Token>& tokens, vector<string>& _funCalls, Expression& exp) {
    if(tokens.empty())
        mad("Missing sub factor expression");
    Expression _exp;
    Token token = tokens.front();

    if(token.type == "OPEN_PARENTHESIS") {
        FunCall _funCall;
        _funCall.parse(exp.variable->name, tokens, _funCalls);
        _exp.type = FUN_CALL;
        _exp.funCall = new FunCall();
        *_exp.funCall = _funCall;
        _funCalls.push_back(_funCall.name);
         token = tokens.front();

    } else if(token.type == "OPEN_BRACKET") {
        Array _arr;
        _arr.parse(exp.variable->name, tokens, _funCalls);
        _exp.type = ARRAY;
        _exp.arr = new Array();
        *_exp.arr = _arr;
        token = tokens.front();

    } else if(token.type == "DOT") {
        StructExp _struct;
        _struct.parse(exp, tokens);
        _exp.type = STRUCT_EXPRESSION;
        _exp.structExp = new StructExp();
        *_exp.structExp = _struct;
    } else if(token.type == "ARROW") {
        PointerExp _pointer;
        _pointer.parse(exp, tokens);
        _exp.type = POINTER_EXPRESSION;
        _exp.pointerExp = new PointerExp();
        *_exp.pointerExp = _pointer;
    }else if (token.type == "MULTIPLICATION") {
        tokens.pop_front();
        token = tokens.front();
        Variable _var;
        _var.parse(tokens);
        _exp.type = VARIABLE;
        _exp.variable = new Variable();
        *_exp.variable = _var;
        PointerExp _pointer;
        _pointer.parse(_exp, tokens);
        _exp.type = POINTER_EXPRESSION;
        _exp.pointerExp = new PointerExp();
        *_exp.pointerExp = _pointer;
    }else if(token.type == "INCREMENT"){
        Increment inc;
        inc.var = *exp.variable;
        _exp.increment = new Increment();
        *_exp.increment = inc;
        tokens.pop_front();
        _exp.type = INCREMENT;
    }else if(token.type == "DECREMENT"){
        Decrement dec;
        dec.var = *exp.variable;
        _exp.decrement = new Decrement();
        *_exp.decrement = dec;
        tokens.pop_front();
        _exp.type = DECREMENT;
    }else {
        Variable _var;
        _var.parse(tokens);
        _exp.type = VARIABLE;
        _exp.variable = new Variable();
        *_exp.variable = _var;
    }

    token = tokens.front();

    if(token.type == "DOT" || token.type == "ARROW" || token.type == "OPEN_BRACKET"
       || token.type == "OPEN_PARENTHESIS" || token.type == "INCREMENT" || token.type == "DECREMENT") {
            _exp = parseSubFactor(tokens, _funCalls, _exp);
    }

    return _exp;
}

Expression Expression::parseFactor (deque<Token>& tokens, vector<string>& _funCalls) {
    if(tokens.empty())
        mad("Missing factor expression");
    Expression exp;
    Token token = tokens.front();
    if(token.type == "OPEN_PARENTHESIS") {
        tokens.pop_front();
        exp = parseAssignment(tokens, _funCalls);
        token = tokens.front();
        if(token.type != "CLOSE_PARENTHESIS")
            mad("Incorrect expression format, missing ')'");
        tokens.pop_front();
    }else if(token.type == "INTEGER" || token.type == "BOOLEAN_TRUE" || token.type == "BOOLEAN_FALSE") {
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
    } else if(token.type == "IDENTIFIER" || token.type == "MULTIPLICATION") {
        exp = parseSubFactor(tokens, _funCalls, exp);
    }else {
        mad("Incorrect expression structure");
    }
    return exp;
}

Expression Expression::parseTerm(deque<Token>& tokens, vector<string>& _funCalls) {
    if(tokens.empty())
        mad("Missing expression");

    Expression factor = parseFactor(tokens, _funCalls);
    Token token = tokens.front();
    while(token.type == "MULTIPLICATION" || token.type == "DIVISION" || token.type == "MOD") {
        tokens.pop_front();
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

Expression Expression::parseAddition(deque<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression term = parseTerm(tokens, _funCalls);
    Token token = tokens.front();
    while(token.type == "NEGATION" || token.type == "ADDITION") {
        tokens.pop_front();
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

Expression Expression::parseRelationalInequalities(deque<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression add = parseAddition(tokens, _funCalls);
    Token token = tokens.front();
    while(token.type == "LESS_OR_EQUAL_TO" || token.type == "LESS_THAN" || token.type == "GREATER_OR_EQUAL_TO" || token.type == "GREATER_THAN") {
        tokens.pop_front();
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

Expression Expression::parseRelationalEqualities(deque<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression rel = parseRelationalInequalities(tokens, _funCalls);
    Token token = tokens.front();
    while(token.type == "EQUAL_TO" || token.type == "NOT_EQUAL_TO") {
        tokens.pop_front();
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

Expression Expression::parseAnd(deque<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression rel = parseRelationalEqualities(tokens, _funCalls);
    Token token = tokens.front();
    while(token.type == "LOGICAL_AND") {
        tokens.pop_front();
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

Expression Expression::parseOr(deque<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression logical = parseAnd(tokens, _funCalls);
    Token token = tokens.front();
    while(token.type == "LOGICAL_OR") {

        tokens.pop_front();
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

Expression Expression::parseConditional(deque<Token>& tokens, vector<string>& _funCalls) {

    if(tokens.empty())
        mad("Expression is empty");

    Expression logical = parseOr(tokens, _funCalls);
    Token token = tokens.front();
    while(token.type == "QUESTION_MARK") {
        tokens.pop_front();
        Expression e1 = logical;
        Expression e2 = parseAssignment(tokens, _funCalls);

        token = tokens.front();
        if(token.type != "COLON")
            mad("Incorrect conditional structure, expected ':'");

        tokens.pop_front();

        Expression e3 = parseConditional(tokens, _funCalls);

        logical.type = CONDITIONAL;

        Conditional _cond = Conditional(e1, e2, e3);
        logical.cond = new Conditional();
        *logical.cond = _cond;
        token = tokens.front();
    }
    return logical;
}

Expression Expression::parseAssignment(deque<Token>& tokens, vector<string>& _funCalls) {
    if(tokens.empty())
        mad("Expression is empty");

    Expression logical = parseConditional(tokens, _funCalls);
    Token token = tokens.front();
    if(token.type == "ASSIGNMENT") {
        if(logical.type != VARIABLE && logical.type != ARRAY && logical.type != STRUCT_EXPRESSION && logical.type != POINTER_EXPRESSION)
            mad("Left part of assignment must be a variable");
        tokens.pop_front();

        Expression _left = logical;
        Expression _rigth = parseAssignment(tokens, _funCalls);
        logical.type = ASSIGNMENT;
        Assignment _assignment = Assignment(_left, _rigth);
        logical.assignment = new Assignment();
        *logical.assignment = _assignment;
    }
    return logical;
}

void Expression::parse(deque<Token>& tokens, vector<string>& _funCalls) {
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
        case ARRAY:
            return arr->translate(fun_name, tabs, funCallNumber, previousCode);
            break;
        case STRUCT_EXPRESSION:
            return structExp->translate(fun_name, tabs, funCallNumber, previousCode);
            break;
        case POINTER_EXPRESSION:
            return pointerExp->translate(fun_name, tabs, funCallNumber, previousCode);
            break;
        case INCREMENT:
            return increment->translate();
            break;
        case DECREMENT:
            return decrement->translate();
            break;
    }
}

void Expression::changeVariablesName(string prefix) {
    switch(type) {
        case UNARY_OPERATOR:
            unaryOperator->changeVariablesName(prefix);
            break;
        case BINARY_OPERATOR:
            binaryOperator->changeVariablesName(prefix);
        case ASSIGNMENT:
            assignment->changeVariablesName(prefix);
            break;
        case VARIABLE:
            variable->changeName(prefix);
            break;
        case CONDITIONAL:
            cond->changeVariablesName(prefix);
            break;
        case FUN_CALL:
            funCall->changeVariablesName(prefix);
            break;
        case ARRAY:
            arr->changeVariablesName(prefix);
            break;
        case STRUCT_EXPRESSION:
            structExp->changeVariablesName(prefix);
            break;
        case POINTER_EXPRESSION:
            pointerExp->changeVariablesName(prefix);
            break;
        case INCREMENT:
            increment->changeVariablesName(prefix);
            break;
        case DECREMENT:
            decrement->changeVariablesName(prefix);
            break;
    }
}
