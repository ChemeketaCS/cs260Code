#include <iostream>

#include "Answer.h"
#include "Templated.h"

using namespace std;


int main()
{
    cout << "This is program B" << endl;

    int a = getAnswer();
    char b = a;

    cout << doubleIt(b) << endl;

    return 0;
}
