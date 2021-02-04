#include "Assignment.h"
#include "Helper.h"
#include "If.h"
#include "Conditional.h"
Assignment::Assignment(Variable& _var, Expression& _exp)
{
    var = _var;
    exp = _exp;
}

Assignment::Assignment()
{
}

string Assignment::translateConditional(string fun_name, int& tabs) {
    If ifStatement;
    ifStatement.condition = exp.cond->condition;

    Assignment trueAssignment;
    trueAssignment.var = var;
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
    falseAssignment.var = var;
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

    return ifStatement.translate(fun_name, tabs);
}

string Assignment::translate(string fun_name, int& tabs) {
    cout<<exp.type<<endl;
    string code = "";
    if(exp.type == ASSIGNMENT)
        code = exp.translate(fun_name, tabs) + ";\n" + printTabs(tabs) + var.translate() + " = " + exp.assignment->var.translate();
    else if(exp.type == CONDITIONAL) {
        code = translateConditional(fun_name, tabs);
    }
    else
        code = var.translate() + " = " + exp.translate(fun_name, tabs);
    return code;
}
