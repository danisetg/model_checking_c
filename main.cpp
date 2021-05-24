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
using namespace std;


int main()
{
   /* int it = 0;

    for(int i = 0; i < 3; i++) {
        for(int h = 0; h < 4; h++) {
            for(int k = 0; k < 5; k++) {
                cout<<"["<<i<<"]["<<h<<"]["<<k<<"]"<<"   ---->   "<<"["<<it<<"]"<<endl;
                it++;
            }
        }
    }
    return 0;*/

    string program = fileToString("C:\\c_tests\\Ejemplos\\triangle.c");
    deque<Token> tokens;
    vector<Token> foundTokens = getTokens(program);

    int len = foundTokens.size();


    for(int i = 0; i < len; i++) {
     //  cout<<foundTokens[i].type<<" "<<foundTokens[i].word<<endl;
        tokens.push_back(foundTokens[i]);
    }

    Program p;
    p.parse(tokens);

    ofstream outfile;
    outfile.open("triangle.pml");
    int tabs = 0;
    outfile<<p.translate(tabs, false);
    outfile.close();

    SpecificationGenerator sp;
    sp.p = p;

    sp.changeDeclarationsToGlobal();
    outfile.open("triangle_cft.pml");
    tabs = 0;
    outfile<<sp.p.translate(tabs, true);

    outfile.close();

    createFolderIfNotExists("test_cases");
    SpinInterface spin;

    spin.generateCFTests(sp);


    return 0;
}
