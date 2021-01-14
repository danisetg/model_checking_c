#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include <Token.h>

using std::vector;
using std::string;
vector<Token> getTokens(string program);

#endif // LEXER_H
