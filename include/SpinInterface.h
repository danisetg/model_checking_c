#ifndef SPININTERFACE_H
#define SPININTERFACE_H
#include "Helper.h"
#include "SpecificationGenerator.h"

class SpinInterface
{
    public:
        SpinInterface();

        string verify(string property, string programFile);
        void generateCCTests(SpecificationGenerator sp);
        void generateDCTests(SpecificationGenerator sp);
        void generateCFTests(SpecificationGenerator sp);
        void generateMCDCTests(SpecificationGenerator sp);
        void generateFPCTests(SpecificationGenerator sp);

};

#endif // SPININTERFACE_H
