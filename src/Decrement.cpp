#include "Decrement.h"

Decrement::Decrement()
{
    //ctor
}

string Decrement::translate() {
    return var.translate() + "--";
}
