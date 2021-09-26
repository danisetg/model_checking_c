#ifndef ARRAY_H
#define ARRAY_H
#include "Helper.h"
#include "Expression.h"

class Array
{
    public:
        vector<Expression> positions;
        string name;
        Array();
        Array(const Array &arr);
        void parse(string _name, deque<Token>& tokens, vector<string>& _funCalls);
        string translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode);
        string getPosition(string fun_name, int& tabs, int& funCallNumber, string& previousCode,
                          vector<int> dimensions, int dimsLength);
        void changeVariablesName(string prefix);
};

#endif // ARRAY_H
