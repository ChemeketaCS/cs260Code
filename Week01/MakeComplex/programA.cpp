#include <iostream>

#include "Answer.h"
#include "Templated.h"

using namespace std;


int main()
{
    cout << "This is program A" << endl;

    int a = getAnswer();
    double b = a;

    cout << doubleIt(b) << endl;

    return 0;
}
