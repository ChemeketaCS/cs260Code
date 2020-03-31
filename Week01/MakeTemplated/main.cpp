#include <iostream>

#include "Double.h"
#include "Helper.h"

using namespace std;

int main()
{
    int* foo = nullptr;     //requires c++11

	int aNum = getANumber();
	int doubled = doubleIt(aNum);
	
	out << aNum << " doubled is " << doubled << endl;

    return 0;
}

