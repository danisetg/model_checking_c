#include "Increment.h"

Increment::Increment()
{
    //ctor
}

string Increment::translate() {
    return var.translate() + "++";
}

void Increment::changeVariablesName(string prefix) {
    var.changeName(prefix);
}
