#include "Expression.h"
#include "Const.h"
#include "Helper.h"
Expression::Expression(const Const &_constant)
{
    constant = _constant;
}
Expression::Expression()
{
}
void Expression::parse (queue<Token>& tokens) {

    if(tokens.empty())
        mad("Expression is empty");

    Const _constant;
    _constant.parse(tokens);

    constant = _constant;
}
string Expression::translate() {
    return constant.translate();
}
