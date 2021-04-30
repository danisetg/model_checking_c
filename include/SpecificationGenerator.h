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

class SpecificationGenerator
{
    public:
        vector<Declaration> variables;
        Program p;
        int dn;
        int cn;
        SpecificationGenerator();

        void changeDeclarationsToGlobal();
        Define parseIfToDefines(string fun_name, Expression exp);
        void checkForIfs(string fun_name, Statement st);
};

#endif // SPECIFICATIONGENERATOR_H
