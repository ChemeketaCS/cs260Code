#include <iostream>

#include "Answer.h"

using namespace std;

int main()
{
    int* foo = nullptr;     //requires c++11

    cout << "The answer is: " << getAnswer() << endl;

    return 0;
}

