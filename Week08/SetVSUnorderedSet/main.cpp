#include <iostream>
#include <unordered_set>
#include <set>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    cout << int(remainder(57,10));

    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, INT_MAX);

    const int SIZE = 1000000;
    {
        set<int> s;
        cout << "Timing " << SIZE << " insertions and lookups in set" << endl;
        time_t start = clock();
        for(int i = 0; i < SIZE; i++) {
            s.insert( distribution(generator) );
        }
        for(int i = 0; i < SIZE; i++) {
            s.find( distribution(generator) );
        }
        time_t end = clock();
        cout << fixed << "Took: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << endl;
        cout << "---------------------" << endl;
    }

    {
        unordered_set<int> s;
        cout << "Timing " << SIZE << " insertions and lookups in unordered set" << endl;
        time_t start = clock();
        for(int i = 0; i < SIZE; i++) {
            s.insert( distribution(generator) );
        }
        for(int i = 0; i < SIZE; i++) {
            s.find( distribution(generator) );
        }
        time_t end = clock();
        cout << fixed << "Took: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << endl;
        cout << "---------------------" << endl;
    }
}
