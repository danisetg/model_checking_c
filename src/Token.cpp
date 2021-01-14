#include "Token.h"

Token::Token(string _type, regex _regExp, string _word)
{
    regExp = _regExp;
    type = _type;
    word = _word;
}
