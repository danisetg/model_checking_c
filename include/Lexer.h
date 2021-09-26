#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include <Token.h>
#include "Helper.h"

using std::vector;
using std::string;
deque<Token> getTokens(string program);

#endif // LEXER_H
