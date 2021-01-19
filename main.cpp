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
    string program = fileToString("C:\\c_tests\\stage_3\\invalid\\no_semicolon.c");

    queue<Token> tokens;
    vector<Token> foundTokens = getTokens(program);

    int len = foundTokens.size();

    for(int i = 0; i < len; i++) {
        tokens.push(foundTokens[i]);
    }

    Program p;
    p.parse(tokens);

    ofstream outfile;
    outfile.open("C:\\c_tests\\stage_3\\valid\\no_semicolon.pml");
    int tabs = 0;
    outfile<<p.translate(tabs);

    outfile.close();
    return 0;
}
