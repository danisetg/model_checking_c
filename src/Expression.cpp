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
Expression::Expression()
{
}
Expression Expression::parseFactor (deque<Token>& tokens, vector<string>& _funCalls) {
    if(tokens.empty())
        mad("Missing factor expression");
    Expression exp;
    Token token = tokens.front();
    cout<<token.word<<endl;
    if(token.type == "OPEN_PARENTHESIS") {
        tokens.pop_front();
        exp = parseAssignment(tokens, _funCalls);
        token = tokens.front();
        if(token.type != "CLOSE_PARENTHESIS")
            mad("Incorrect expression format, missing ')'");
        tokens.pop_front();
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
        } else if(token.type == "OPEN_BRACKET") {
            Array _arr;
            _arr.parse(_var.name, tokens, _funCalls);
            exp.type = ARRAY;
            exp.arr = new Array();
            *exp.arr = _arr;
            token = tokens.front();
            if(token.type == "DOT") {
                StructExp _struct;
                _struct.parse(exp, tokens);
                exp.type = STRUCT_EXPRESSION;
                exp.structExp = new StructExp();
                *exp.structExp = _struct;
            }
            cout<<" "<<token.type<<endl;
        }else if(token.type == "INCREMENT"){
            Increment inc;
            inc.var = _var;
            exp.increment = new Increment();
            *exp.increment = inc;
            tokens.pop_front();
            exp.type = INCREMENT;
        }else if(token.type == "DECREMENT"){
            Decrement dec;
            dec.var = _var;
            exp.decrement = new Decrement();
            *exp.decrement = dec;
            tokens.pop_front();
            exp.type = DECREMENT;
        } else if(token.type == "DOT") {
            Expression _exp;
            _exp.type = VARIABLE;
            _exp.variable = new Variable();
            *_exp.variable = _var;
            StructExp _struct;
            _struct.parse(_exp, tokens);
            exp.type = STRUCT_EXPRESSION;
            exp.structExp = new StructExp();
            *exp.structExp = _struct;
        }else {
            exp.type = VARIABLE;
            exp.variable = new Variable();
            *exp.variable = _var;
        }

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
        cout<<token.word<<endl;
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
    cout<<token.word<<endl;
    if(token.type == "ASSIGNMENT") {
        if(logical.type != VARIABLE && logical.type != ARRAY && logical.type != STRUCT_EXPRESSION)
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
    cout<<type<<endl;
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
        case INCREMENT:
            return increment->translate();
            break;
        case DECREMENT:
            return decrement->translate();
            break;
    }
}
