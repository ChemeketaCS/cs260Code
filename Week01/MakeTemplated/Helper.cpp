//Simple file which relies on Double.h's templated code

#include "Double.h"
#include "Helper.h"

int getANumber() {
	int x = 10;
	x = doubleIt(x);
	return x;
}