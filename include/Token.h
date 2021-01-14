#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <regex>
using std::string;
using std::regex;
class Token
{
    public:
        string type;
        string word;
        regex regExp;
        Token(string _type, regex _regExp, string _word);

};

#endif // TOKEN_H
