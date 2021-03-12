#include "Goto.h"

Goto::Goto()
{
    //ctor
}


void Goto::parse(deque<Token>& tokens) {
  Token token = tokens.front();

  if(token.type != "GOTO_KEYWORD")
    mad("not a goto");

  tokens.pop_front();
  token = tokens.front();

  if(token.type != "IDENTIFIER")
    mad("missing label name");

  labelName = token.word;

  tokens.pop_front();
}

string Goto::translate() {
    return  "goto " + labelName;
}

