#ifndef SPECIFICATIONGENERATOR_H
#define SPECIFICATIONGENERATOR_H
#include "Helper.h"
#include "Program.h"
#include "If.h"
#include "BinaryOperator.h"
#include "While.h"
#include "For.h"
#include "DoWhile.h"
#include "Variable.h"
#include "LabeledStatement.h"
#include "Print.h"
#include "Atomic.h";
#include "Assignment.h"
#include "Goto.h"

class SpecificationGenerator
{
    public:
        vector<Declaration> variables;
        Program p;
        int dn;
        int cn;
        SpecificationGenerator();
        SpecificationGenerator(const Program &_p);
        void generateCFSpecifications(string resultsAddr, string filename);
        void changeDeclarationsToGlobal();
        Define parseIfToDefines(string fun_name, Expression exp);
        void checkForIfs(string fun_name, Statement &st);
        vector<string> generateCCSpecifications();
        vector<string> generateDCSpecifications();
        void addMCDCAuxiliaryVariables();
        void addStartLabel();
        void addResetButton();
        void translateMCDC(string resultsAddr, string filename);
        void modifyIfs(string fun_name, Statement& st);
        void addInvariantsToIf(Atomic &atomic, int _dn);
        void getConditions(Expression exp, vector<string> &conditions);
        vector<string> generateMCDCSpecifications(string resultsAddr, string filename);
};

#endif // SPECIFICATIONGENERATOR_H
