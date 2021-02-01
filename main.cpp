#include <iostream>
#include "Helper.h"
#include <vector>
#include <Lexer.h>
#include <regex>
#include <queue>
#include "Token.h"
#include "Program.h"
#include <fstream>
#include <sstream>
#include "Fun.h"
using namespace std;


int main()
{
    string program = fileToString("C:\\c_tests\\stage_6\\valid\\statement\\multiple_if.c");
    queue<Token> tokens;
    vector<Token> foundTokens = getTokens(program);

    int len = foundTokens.size();

    int a = 1;

    if (a > 5){
        //do something
    } else {
        //do something else
    }


    for(int i = 0; i < len; i++) {
 //       cout<<foundTokens[i].type<<" "<<foundTokens[i].word<<endl;
        tokens.push(foundTokens[i]);
    }

    Program p;
    p.parse(tokens);

    ofstream outfile;
    outfile.open("C:\\c_tests\\stage_6\\valid\\statement\\multiple_if.pml");
    int tabs = 0;
    outfile<<p.translate(tabs);

    outfile.close();
    return 0;
}
