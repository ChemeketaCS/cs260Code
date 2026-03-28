// Simple file which relies on Double.h's templated code

#include "Helper.h"
#include "Double.h"

int getANumber() {
  int x = 10;
  x = doubleIt(x);
  return x;
}