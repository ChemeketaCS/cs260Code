//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//Hide some false warnings - this is supposed to look commented out
// clazy:skip


//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//Declare functions we will test
void mergeFunc(int arr[], int low, int mid, int high, int temp[]);
void mergeSort(int arr[], int arrSize);

#include <algorithm>
#include <random>

using namespace std;

TEST_CASE( "Merge/AllEqualHalves" ) {
    int mergeArr[]  = {1, 3, 5, 2, 4, 6};
    const int size = 6;

    //Copy to compare against
    int key[size];
    std::copy(mergeArr, mergeArr + size, key);
    std::sort(key, key + size);

    int temp[size] = {};
    mergeFunc(mergeArr, 0, 2, 5, temp);

    bool isSorted = std::is_sorted(mergeArr, mergeArr + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(mergeArr, mergeArr + size, key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}

TEST_CASE( "Merge/AllUnequalHalves" ) {
    int mergeArr[]  = {1, 8, 10, 20, 6, 7, 15};
    const int size = 7;

    //Copy to compare against
    int key[size];
    std::copy(mergeArr, mergeArr + size, key);
    std::sort(key, key + size);

    int temp[size] = {};
    mergeFunc(mergeArr, 0, 3, 6, temp);

    bool isSorted = std::is_sorted(mergeArr, mergeArr + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(mergeArr, mergeArr + size, key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}

TEST_CASE( "Merge/AllUnequalHalves2" ) {
    int mergeArr[]  = {1, 3, 2, 4, 6, 8, 10};
    const int size = 7;

    //Copy to compare against
    int key[size];
    std::copy(mergeArr, mergeArr + size, key);
    std::sort(key, key + size);

    int temp[size] = {};
    mergeFunc(mergeArr, 0, 1, 6, temp);

    bool isSorted = std::is_sorted(mergeArr, mergeArr + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(mergeArr, mergeArr + size, key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}

TEST_CASE( "Merge/Partial" ) {
    //Test to see if sorting just a partial range works
    int mergeArr[]  = {999, 999, 4, 8, 3, 12, 999};
    const int size = 7;

    //Copy to compare against
    int key[size];
    std::copy(mergeArr, mergeArr + size, key);
    //sort just the relevent part
    std::sort(key + 2, key + (size - 1));

    int temp[size] = {};
    mergeFunc(mergeArr, 2, 3, 5, temp);

    //see if 2-5 are sorted
    bool isSorted = std::is_sorted(mergeArr + 2, mergeArr + 6);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(mergeArr, mergeArr + size, key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}




TEST_CASE( "MergeSort/Simple" ) {
    int list[] = {12, 9, 16, 2, 1, 16, 18, 7};
    const int size = 8;

    //Copy to compare against
    int list_key[size];
    std::copy(list, list + size, list_key);
    std::sort(list_key, list_key + size);

    mergeSort(list, size);

    bool isSorted = std::is_sorted(list, list + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(list, list + size, list_key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}

//get value 0-999,999
int randInt() {
    static default_random_engine generator;
    static uniform_int_distribution<int> distribution(0,999999);
    return distribution(generator);
}

TEST_CASE( "MergeSort/Big" ) {
    const int size = 10001;
    int* list = new int[size];
    //Fill with random numbers
    std::generate(list, list + size, randInt);

    //Copy to compare against
    int* list_key = new int[size];
    std::copy(list, list + size, list_key);
    std::sort(list_key, list_key + size);

    mergeSort(list, size);

    bool isSorted = std::is_sorted(list, list + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(list, list + size, list_key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
    delete [] list;
    delete [] list_key;
}
