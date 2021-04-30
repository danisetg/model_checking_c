#include "Decrement.h"

Decrement::Decrement()
{
    //ctor
}

string Decrement::translate() {
    return var.translate() + "--";
}

void Decrement::changeVariablesName(string prefix) {
    var.changeName(prefix);
}
