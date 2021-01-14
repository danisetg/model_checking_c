#ifndef CONST_H
#define CONST_H
#include <iostream>
#include <queue>
#include <Token.h>
#include <sstream>
#include <fstream>
using std::string;
using std::queue;
using std::ofstream;
class Const
{
    public:
        string value;
        Const();
        Const(string _value);
        void parse(queue<Token>& tokens);
        string translate();

};

#endif // CONST_H
