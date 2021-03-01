#include "Assignment.h"
#include "Helper.h"
#include "If.h"
#include "Conditional.h"
Assignment::Assignment(Expression& _leftSide, Expression& _exp)
{
    leftSide = _leftSide;
    exp = _exp;
}

Assignment::Assignment()
{
}

string Assignment::translateConditional(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    If ifStatement;
    ifStatement.condition = exp.cond->condition;

    Assignment trueAssignment;
    trueAssignment.leftSide = leftSide;
    trueAssignment.exp = exp.cond->trueAssign;

    Expression trueExpression;
    trueExpression.type = ASSIGNMENT;
    trueExpression.assignment = new Assignment();
    *trueExpression.assignment = trueAssignment;

    Statement trueStatement;
    trueStatement.type = EXPRESSION;
    trueStatement.expression = new Expression();
    *trueStatement.expression = trueExpression;


    Assignment falseAssignment;
    falseAssignment.leftSide = leftSide;
    falseAssignment.exp = exp.cond->falseAssign;

    Expression falseExpression;
    falseExpression.type = ASSIGNMENT;
    falseExpression.assignment = new Assignment();
    *falseExpression.assignment = falseAssignment;

    Statement falseStatement;
    falseStatement.type = EXPRESSION;
    falseStatement.expression = new Expression();
    *falseStatement.expression = falseExpression;

    ifStatement.ifBody.push_back(trueStatement);
    ifStatement.elseBody.push_back(falseStatement);

    return ifStatement.translate(fun_name, tabs, funCallNumber, previousCode);
}

string Assignment::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    cout<<exp.type<<endl;
    string code = "";
    if(exp.type == ASSIGNMENT)
        code = exp.translate(fun_name, tabs, funCallNumber, previousCode) + ";\n" + printTabs(tabs) + leftSide.translate(fun_name, tabs, funCallNumber, previousCode) + " = " + exp.assignment->leftSide.translate(fun_name, tabs, funCallNumber, previousCode);
    else if(exp.type == CONDITIONAL) {
        code = translateConditional(fun_name, tabs, funCallNumber, previousCode);
    } else
        code = leftSide.translate(fun_name, tabs, funCallNumber, previousCode) + " = " + exp.translate(fun_name, tabs, funCallNumber, previousCode);
    return code;
}
