#ifndef SCAN_H
#define SCAN_H
#include "Helper.h"
#include "Expression.h"

class Scan
{
    public:
        vector<string> variables;
        vector<pair<int, int> > limits;
        Scan();
        Scan(const Scan &scan);
        void parse(deque<Token>& tokens);
        string translate(int& tabs);
        void changeVariablesName(string prefix);
};

#endif // SCAN_H
