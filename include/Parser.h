#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <Token.h>
#include "Program.h"
using std::vector;
using std::string;
using std::queue;

Program parseProgram(queue<Token> &tokens);


#endif // PARSER_H
