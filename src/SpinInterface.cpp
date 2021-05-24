#include "SpinInterface.h"

SpinInterface::SpinInterface()
{
    //ctor
}

string SpinInterface::verify(string property, string programFile) {
    string command = "spin -a -f \"" + property + "\" " + programFile ;
    cout<<command<<endl;
    string result = property + '\n';
    string tmp = exec(command.c_str());
    if(tmp.length())
        return tmp;
    else {
        exec("gcc -DSAFETY -o pan pan.c");
        exec("pan");
        command = "spin -t -p -g -l " + programFile;
        result += exec(command.c_str());
        return result;
    }
}

void SpinInterface::generateCCTests(SpecificationGenerator sp) {
    vector<string> specifications = sp.generateCCSpecifications();
    ofstream outfile;
    createFolderIfNotExists("test_cases\\cc");
    for(int i = 0; i < specifications.size(); i++) {
        outfile.open("test_cases\\cc\\triangle_cft_case_ " + to_string(i + 1) + ".txt");
        outfile<<verify(specifications[i], "triangle_cft.pml");
        outfile.close();
    }
}

void SpinInterface::generateDCTests(SpecificationGenerator sp) {
    vector<string> specifications = sp.generateDCSpecifications();
    ofstream outfile;
    createFolderIfNotExists("test_cases\\dc");
    for(int i = 0; i < specifications.size(); i++) {
        outfile.open("test_cases\\dc\\triangle_cft_case_ " + to_string(i + 1) + ".txt");
        outfile<<verify(specifications[i], "triangle_cft.pml");
        outfile.close();
    }
}

void SpinInterface::generateMCDCTests(SpecificationGenerator sp) {
    vector<string> specifications = sp.generateMCDCSpecifications();
    ofstream outfile;
    createFolderIfNotExists("test_cases\\mcdc");
    for(int i = 0; i < specifications.size(); i++) {
        outfile.open("test_cases\\mcdc\\triangle_cft_case_ " + to_string(i + 1) + ".txt");
        outfile<<verify(specifications[i], "triangle_mcdc.pml");
        outfile.close();
    }
}

void SpinInterface::generateFPCTests(SpecificationGenerator sp) {
    vector<string> specifications = sp.generateFPCSpecifications();
    ofstream outfile;
    createFolderIfNotExists("test_cases\\fpc");
    for(int i = 0; i < specifications.size(); i++) {
        outfile.open("test_cases\\fpc\\triangle_cft_case_ " + to_string(i + 1) + ".txt");
        outfile<<verify(specifications[i], "triangle_mcdc.pml");
        outfile.close();
    }
}

void SpinInterface::generateCFTests(SpecificationGenerator sp) {
    generateCCTests(sp);
    generateDCTests(sp);
    generateMCDCTests(sp);
    generateFPCTests(sp);
}
