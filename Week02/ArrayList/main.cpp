#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

#include "ArrayList.h"

using namespace std;

//get random num 0-99,999
int getRandom();

int main() {
    for(int size = 500; size <= 5000000; size *= 10) {
        clock_t start = clock();

        ArrayList<int> myList;
        for(int i = 0; i < size; i++) {
            myList.insertEnd(getRandom());
            //myList.insertAt(0, getRandom());
        }

        clock_t duration = clock() - start;
        cout << fixed << setprecision(5);
        cout << "Adding " << size << " elemenets took: ";
        cout << (1.0 * duration / CLOCKS_PER_SEC) << " seconds" << endl;
        cout << "      ~" << (1.0 * duration / CLOCKS_PER_SEC)  / size * 1000000000 << " ns per element" << endl;
    }
}



//-----------------------------------------------------------------------
int getRandom() {
    //Reuse one generator and distribution object over lifetime of function:
    static default_random_engine generator(time(nullptr));
    static uniform_int_distribution<int> distribution(0,99999);

    //Use those to generate a new value
    return distribution(generator);
}
