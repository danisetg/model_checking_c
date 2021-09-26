#include <iostream>
#include "Helper.h"
#include <vector>
#include <Lexer.h>
#include <regex>
#include <deque>
#include "Token.h"
#include "Program.h"
#include <fstream>
#include <sstream>
#include "Fun.h"
#include "SpecificationGenerator.h"
#include "SpinInterface.h"
#include "DFSpecificationGenerator.h"
#include <locale.h>
using namespace std;

string getFilename(string addr) {
    return addr.substr(addr.find_last_of('\\') + 1, addr.find_last_of('.') - addr.find_last_of('\\') - 1);
}

string getFileExtension(string addr) {
    return addr.substr(addr.find_last_of('.') + 1);
}

int main()
{
    //Function for allowing to print accents in console.
    setlocale(LC_ALL, "");

    string programAdress;

    bool isAValidCFile = false;

    //iterates until a valid C file address is provided
    do {
        //Ask for file address and save it in programAddress variable
        printf("Introduzca la dirección del archivo .c del programa\n");
        cin>>programAdress;

        isAValidCFile = (getFileExtension(programAdress) == "c");

        if(!isAValidCFile)
            printf("Debe introducir la dirección un archivo .c\n");

    } while(!isAValidCFile);

    string fileName = getFilename(programAdress);
    string resultsAddr = "results\\" + fileName;

    //creates a directory for storing the results
    createFolderIfNotExists("results");
    createFolderIfNotExists("results\\" + fileName);


    //Creates a string with the code of the program.
    string programString = fileToString(programAdress);

    //get the tokens from Lexer's getTokens function.
    deque<Token> tokens = getTokens(programString);

    //Creates Program p which will be the root of the AST
    Program p;
    //builds the AST
    p.parse(tokens);

    //initialize the tabs for the translation indentation.
    int tabs = 0;

    //Creates an ofstream for creating the files with the results
    ofstream outfile;
    //creates and open a new file with .pml extension for storing the translation result
    outfile.open(resultsAddr + "\\" + fileName + ".pml");
    //translates the program and stores it in the opened file.
    outfile<<p.translate(tabs, false);
    //closes the file.
    outfile.close();

    return 0;

    //initialize an specification generator for control flow oriented specifications.
    SpecificationGenerator sp = SpecificationGenerator(p);
    sp.generateCFSpecifications(resultsAddr, fileName);

    //creates a spin interface instance and generates control flow oriented tests
    SpinInterface spin;
    spin.generateCFTests(sp, resultsAddr, fileName);

     //initialize an specification generator for data flow oriented specifications.
    DFSpecificationGenerator df = DFSpecificationGenerator(p);
    df.generateDFSpecifications(resultsAddr, fileName);

    //generates data flow oriented tests
    spin.generateDFTests(df, resultsAddr, fileName);

    return 0;
}
