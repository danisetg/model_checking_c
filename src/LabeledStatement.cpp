#include "LabeledStatement.h"

LabeledStatement::LabeledStatement()
{
    //ctor
}

void LabeledStatement::parse(deque<Token>& tokens, vector<Statement>& statements, vector<string>& _funCalls) {
  Token token = tokens.front();

  if(token.type != "IDENTIFIER")
    mad("not a label");

  labelName = token.word;

  tokens.pop_front();

  token = tokens.front();

  if(token.type != "COLON")
    mad("missing ':'");

  tokens.pop_front();
  Statement _statement;
  _statement.parse(tokens, statements, _funCalls);

  statement = _statement;
}

string LabeledStatement::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    return labelName + ":" + statement.translate(fun_name, tabs, funCallNumber, previousCode);
}

void LabeledStatement::changeVariablesName(string prefix) {
    statement.changeVariablesName(prefix);
}
