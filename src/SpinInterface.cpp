#include "SpinInterface.h"

SpinInterface::SpinInterface()
{
    //ctor
}

string SpinInterface::verify(string property, string resultsAddr, string filename) {
    string programFile = filename + ".pml";
    string command = "cd " + resultsAddr + " && spin -a -f \"" + property + "\" " + programFile ;
    cout<<command<<endl;
    string result = "";
    string tmp = exec(command.c_str());
    if(tmp.length())
        return tmp;
    else {
        command = "cd " + resultsAddr + " && gcc -DSAFETY -o pan pan.c";
        exec(command.c_str());
        command = "cd " + resultsAddr + " && pan";
        string verifResult = exec(command.c_str());
        cout<<verifResult<<endl;
        if(verifResult.find("errors: 0") == std::string::npos) {
            command = "cd " + resultsAddr + " && spin -t -p -g -l " + programFile;
            result += exec(command.c_str());
            return result;
        }
        return "";

    }
}

void SpinInterface::generateCCTests(SpecificationGenerator sp, string resultsAddr, string filename) {
    caseTaken.clear();
    vector<string> specifications = sp.generateCCSpecifications();
    ofstream outfile;
    string resultsFolder = resultsAddr +  "\\test_cases\\cc";
    createFolderIfNotExists(resultsFolder);
    for(int i = 0; i < specifications.size(); i++) {

        string response = verify(specifications[i], resultsAddr, filename + "_cft");
        if(response.length()) {
            response = filterOutput(response);
            cout<<response<<endl;
            if(!caseTaken[response]) {
                outfile.open(resultsFolder + "\\" + "cc_case_" + to_string(i + 1) + ".txt");
                caseTaken[response] = true;
                outfile<<specifications[i] + '\n' + response;
            }
        }
        outfile.close();
    }
}

void SpinInterface::generateDCTests(SpecificationGenerator sp, string resultsAddr, string filename) {
    caseTaken.clear();
    vector<string> specifications = sp.generateDCSpecifications();
    ofstream outfile;
    string resultsFolder = resultsAddr +  "\\test_cases\\dc";
    createFolderIfNotExists(resultsFolder);
    for(int i = 0; i < specifications.size(); i++) {
        string response = verify(specifications[i], resultsAddr, filename + "_cft");
        if(response.length()) {
            response = filterOutput(response);
            if(!caseTaken[response]) {
                outfile.open(resultsFolder + "\\" + "dc_case_" + to_string(i + 1) + ".txt");
                caseTaken[response] = true;
                outfile<<specifications[i] + '\n' + response;
            }
        }
        outfile.close();
    }
}

void SpinInterface::generateMCDCTests(SpecificationGenerator sp, string resultsAddr, string filename) {
    caseTaken.clear();
    vector<string> specifications = sp.generateMCDCSpecifications(resultsAddr, filename);
    ofstream outfile;
    string resultsFolder = resultsAddr + "\\test_cases\\mcdc";
    createFolderIfNotExists(resultsFolder);
    for(int i = 0; i < specifications.size(); i++) {
        string response = verify(specifications[i], resultsAddr, filename + "_mcdc");
        if(response.length()) {
            response = filterOutput(response);
            if(!caseTaken[response]) {
                outfile.open(resultsFolder + "\\" + "mcdc_case_" + to_string(i + 1) + ".txt");
                caseTaken[response] = true;
                outfile<<specifications[i] + '\n' + response;
            }
        }
        outfile.close();
    }
}

void SpinInterface::generateCFTests(SpecificationGenerator sp, string resultsAddr, string filename) {
    createFolderIfNotExists(resultsAddr + "\\test_cases");
    generateCCTests(sp, resultsAddr, filename);
    generateDCTests(sp, resultsAddr, filename);
    generateMCDCTests(sp, resultsAddr, filename);
}

void SpinInterface::generateAllDefsTests(DFSpecificationGenerator df, string resultsAddr, string filename) {
    caseTaken.clear();
    vector<string> specifications = df.generateAllDefsSpecifications();
    ofstream outfile;
    string resultsFolder = resultsAddr + "\\test_cases\\all_defs";
    createFolderIfNotExists(resultsFolder);
    for(int i = 0; i < specifications.size(); i++) {
        string response = verify(specifications[i], resultsAddr, filename + "_dft");
        if(response.length()) {
            response = filterOutput(response);
            if(!caseTaken[response]) {
                outfile.open(resultsFolder + "\\" + "all_defs_case_" + to_string(i + 1) + ".txt");
                caseTaken[response] = true;
                outfile<<specifications[i] + '\n' + response;
            }
        }
        outfile.close();
    }
}
void SpinInterface::generateAllUsesTests(DFSpecificationGenerator df, string resultsAddr, string filename) {
    caseTaken.clear();
    vector<string> specifications = df.generateAllUsesSpecifications();
    ofstream outfile;
    string resultsFolder = resultsAddr + "\\test_cases\\all_uses";
    createFolderIfNotExists(resultsFolder);
    for(int i = 0; i < specifications.size(); i++) {
        string response = verify(specifications[i], resultsAddr, filename + "_dft");
        if(response.length()) {
            response = filterOutput(response);
            if(!caseTaken[response]) {
                outfile.open(resultsFolder + "\\" + "all_uses_case_" + to_string(i + 1) + ".txt");
                caseTaken[response] = true;
                outfile<<specifications[i] + '\n' + response;
            }
        }
        outfile.close();
    }
}

void SpinInterface::generateDFTests(DFSpecificationGenerator df, string resultsAddr, string filename) {
    generateAllDefsTests(df, resultsAddr, filename);
    generateAllUsesTests(df, resultsAddr, filename);
}

string SpinInterface::filterOutput(string response) {
    vector<string> lines = split(response, '\n');
    string filtered = "";

    for(int i = 0; i < lines.size(); i++) {
        if (lines[i].find("input") == std::string::npos && lines[i].find("Starting") == std::string::npos && lines[i].find("spin:") == std::string::npos) {
            filtered += lines[i] + '\n';
        }
    }
    return filtered;
}


