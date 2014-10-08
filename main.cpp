#include <iostream>
#include "vehicle.h"

using namespace std;

void copypointer(SP<A>& spa){
    SP<A> spa1;
    spa1 = spa;
    spa1->PrintNum();
}

int main()
{
    SP<A> spa = new A(10);
    spa->PrintNum();
    copypointer(spa);
    spa->PrintNum();

    return 0;
}