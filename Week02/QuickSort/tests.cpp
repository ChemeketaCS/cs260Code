//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

//This pragma supresses a bunch of warnings QTCreator produces (and should not)
#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"

//Hide some false warnings - this is supposed to look commented out
// clazy:skip

//Tell clang analyzer to ignore doctest.h
#ifndef __clang_analyzer__
#include "doctest.h"
#endif


//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//Declare functions we will test
int partitionFunct(int arr[], int low, int high);
void quickSort(int arr[], int arrSize);

#include <algorithm>
#include <random>

using namespace std;

TEST_CASE( "Partition/Basic" ) {
    int arr[]  = {12, 18, 3, 20, 6, 7, 15};
    const int size = 7;

    int backup[size];  //used to verify all values are kept
    std::copy(arr, arr + size, backup);

    int pivotLocation = partitionFunct(arr, 0, size - 1);

    INFO("You claimed the pivot was " << arr[pivotLocation]
         << " located at " << pivotLocation);
    for(int i = 0; i < pivotLocation; i++)
        REQUIRE( arr[i] <= arr[pivotLocation] );
    for(int i = pivotLocation + 1; i < size; i++)
        REQUIRE( arr[i] >= arr[pivotLocation] );

    bool hasAll = true;
    for(int val : arr) {
        if(std::find(backup, backup+size, val) == backup+size) {
            hasAll = false;
            break;
        }
    }
    INFO("Your array does not have the right elements!");
    REQUIRE( hasAll == true );
}

TEST_CASE( "Partition/Duplicates" ) {
    int arr[]  = {5, 10, 5, 12, 2, 18, 5, 10};
    const int size = 8;

    int backup[size];  //used to verify all values are kept
    std::copy(arr, arr + size, backup);

    int pivotLocation = partitionFunct(arr, 0, size - 1);

    INFO("You claimed the pivot was " << arr[pivotLocation]
         << " located at " << pivotLocation);
    for(int i = 0; i < pivotLocation; i++)
        REQUIRE( arr[i] <= arr[pivotLocation] );
    for(int i = pivotLocation + 1; i < size; i++)
        REQUIRE( arr[i] >= arr[pivotLocation] );

    bool hasAll = true;
    for(int val : arr) {
        if(std::find(backup, backup+size, val) == backup+size) {
            hasAll = false;
            break;
        }
    }
    INFO("Your array does not have the right elements!");
    REQUIRE( hasAll == true );
}

TEST_CASE( "Partition/Partial" ) {
    //Partitions only the range 1-5
    int arr[]  = {999, 6, 10, 2, 8, 4, 999};
    const int size = 7;

    int backup[size];  //used to verify all values are kept
    std::copy(arr, arr + size, backup);

    int pivotLocation = partitionFunct(arr, 1, 5);

    INFO("You claimed the pivot was " << arr[pivotLocation]
         << " located at " << pivotLocation);
    for(int i = 2; i < pivotLocation; i++)
        REQUIRE( arr[i] <= arr[pivotLocation] );
    for(int i = pivotLocation + 1; i < 6; i++)
        REQUIRE( arr[i] >= arr[pivotLocation] );

    bool hasAll = true;
    for(int val : arr) {
        if(std::find(backup, backup+size, val) == backup+size) {
            hasAll = false;
            break;
        }
    }
    INFO("Your array does not have the right elements!");
    REQUIRE( hasAll == true );
}




TEST_CASE( "QuickSort/Simple" ) {
    int list[] = {12, 9, 16, 2, 1, 16, 18, 7};
    const int size = 8;

    //Copy to compare against
    int list_key[size];
    std::copy(list, list + size, list_key);
    std::sort(list_key, list_key + size);

    quickSort(list, size);

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

TEST_CASE( "QuickSort/Big" ) {
    const int size = 10001;
    int* list = new int[size];
    //Fill with random numbers
    std::generate(list, list + size, randInt);

    //Copy to compare against
    int* list_key = new int[size];
    std::copy(list, list + size, list_key);
    std::sort(list_key, list_key + size);

    quickSort(list, size);

    bool isSorted = std::is_sorted(list, list + size);
    REQUIRE( isSorted == true );

    bool correctVals = std::equal(list, list + size, list_key);
    INFO("Your array does not have the right elements!");
    REQUIRE( correctVals == true );
}
