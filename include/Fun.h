#ifndef FUN_H
#define FUN_H
#include <string>
#include <Return.h>

using std::string;

class Fun
{
    public:
        string name;
        Return statement;
        Fun();
        Fun(string _name, Return &_statement);
        void parse(queue<Token>& tokens);
        string translate(int& tabs);
};

#endif // FUN_H
