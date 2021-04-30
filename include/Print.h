#ifndef PRINT_H
#define PRINT_H
#include "Helper.h"

class Print
{
    public:
        string message;
        vector<string> variables;
        Print();
        void parse(deque<Token>& tokens);
        string translate(int& tabs);
        void changeVariablesName(string prefix);
};

#endif // PRINT_H
