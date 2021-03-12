#include "Increment.h"

Increment::Increment()
{
    //ctor
}

string Increment::translate() {
    return var.translate() + "++";
}
