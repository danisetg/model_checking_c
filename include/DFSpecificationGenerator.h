#ifndef DFSPECIFICATIONGENERATOR_H
#define DFSPECIFICATIONGENERATOR_H
#include "Helper.h"
#include "Program.h"
#include "UnaryOperator.h"
#include "BinaryOperator.h"
#include "Assignment.h"
#include "Conditional.h"
#include "FunCall.h"
#include "Increment.h"
#include "Decrement.h"
#include "If.h"
#include "While.h"
#include "DoWhile.h"
#include "Print.h"
#include "Scan.h"
#include "LabeledStatement.h"

class DFSpecificationGenerator
{
    public:
        Program p;
        DFSpecificationGenerator();
        DFSpecificationGenerator(const Program &_p);
        map<string, int> variableIndex;
        map<string, bool> labelExists;
        int numVariables;
        vector<vector<string> > defs;
        vector<vector<string> > uses;
        vector<string> variables;
        void generateDFSpecifications(string resultsAddr, string filename);
        void modifyProgram();
        void addLabels(Statement &st, int &statementNumber, string fun_name);
        void getVectorStatements(vector<Statement> &statements, int &statementNumber, string fun_name);
        vector<string> getLabels(Expression exp, int statementNumber, bool def);
        vector<string> getVariablesLabels(vector<string> variables, int statementNumber, bool def);
        vector<string> generateAllDefsSpecifications();
        vector<string> generateAllUsesSpecifications();
        void addDefine(string label, string fun_name);

};

#endif // DFSPECIFICATIONGENERATOR_H
