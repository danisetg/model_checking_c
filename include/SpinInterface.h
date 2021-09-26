#ifndef SPININTERFACE_H
#define SPININTERFACE_H
#include "Helper.h"
#include "SpecificationGenerator.h"
#include "DFSpecificationGenerator.h"

class SpinInterface
{
    public:
        SpinInterface();
        map<string, bool> caseTaken;
        string verify(string property, string resultsAddr, string filename);
        void generateCCTests(SpecificationGenerator sp, string resultsAddr, string filename);
        void generateDCTests(SpecificationGenerator sp, string resultsAddr, string filename);
        void generateCFTests(SpecificationGenerator sp, string resultsAddr, string filename);
        void generateMCDCTests(SpecificationGenerator sp, string resultsAddr, string filename);
        void generateFPCTests(SpecificationGenerator sp, string resultsAddr, string filename);
        void generateAllDefsTests(DFSpecificationGenerator df, string resultsAddr, string filename);
        void generateAllUsesTests(DFSpecificationGenerator df, string resultsAddr, string filename);
        void generateDFTests(DFSpecificationGenerator df, string resultsAddr, string filename);
        string filterOutput(string response);

};

#endif // SPININTERFACE_H
