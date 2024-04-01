//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//Hide some false warnings - this is supposed to look commented out
// clazy:skip

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include <vector>
#include <algorithm>

#include "MaxHeap.h"
//#include "code.cpp"     //Your code in cpplab

using namespace std;

/*
 * Forcibly set heap to known state:
 *       100
 *      /   \
 *     50    60
 *    / \    /
 *   30 20  10
*/
//Built to take existing heap to avoid using copy ctor or assignment
void buildTestHeap(MaxHeap<int>& h) {
    delete [] h.data;
    h.heapSize = 6;
    h.capacity = 32;
    //Intentionally has extra 100... not technically part of heap
    h.data = new int[32] {100, 50, 60, 30, 20, 10, 100};
}

TEST_CASE( "largestChildIndex" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());
    REQUIRE( h.largestChildIndex(0) == 2 );
    REQUIRE( h.largestChildIndex(1) == 3 );
    REQUIRE( h.largestChildIndex(2) == 5 );
    REQUIRE( h.largestChildIndex(3) == -1 );
    REQUIRE( h.largestChildIndex(4) == -1 );
    REQUIRE( h.largestChildIndex(5) == -1 );
}


TEST_CASE( "addTestOne" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    h.add(15);
    REQUIRE( h.heapSize == 7 );
    REQUIRE( h.data[2] == 60 );
    REQUIRE( h.data[6] == 15 );
}

TEST_CASE( "addTestTwo" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    h.add(75);
    REQUIRE( h.heapSize == 7 );
    REQUIRE( h.data[2] == 75 );
    REQUIRE( h.data[6] == 60 );
}

TEST_CASE( "addTestTwo" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    h.add(15);
    h.add(75);
    REQUIRE( h.heapSize == 8 );
    REQUIRE( h.data[1] == 75 );
    REQUIRE( h.data[3] == 50 );
    REQUIRE( h.data[7] == 30 );
}


TEST_CASE( "addTestThree" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    h.add(15);
    h.add(15);
    h.add(15);
    h.add(200);
    REQUIRE( h.heapSize == 10 );
    REQUIRE( h.data[0] == 200 );
    REQUIRE( h.data[1] == 100 );
    REQUIRE( h.data[4] == 50 );
    REQUIRE( h.data[9] == 20 );
}



TEST_CASE( "removeOne" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    int temp = h.removeMax();
    REQUIRE( temp == 100 );
    REQUIRE( h.data[0] == 60 );
    REQUIRE( h.data[2] == 10 );
    REQUIRE( h.heapSize == 5 );
}


TEST_CASE( "removeTwo" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    h.removeMax();
    int temp = h.removeMax();
    REQUIRE( temp == 60 );
    REQUIRE( h.data[0] == 50 );
    REQUIRE( h.data[1] == 30 );
    REQUIRE( h.data[3] == 20 );
    REQUIRE( h.heapSize == 4 );
}

TEST_CASE( "removeAll" ) {
    MaxHeap<int> h;
    buildTestHeap(h);  //100 50 60 30 20 10

    INFO(h.toString());

    h.removeMax();
    h.removeMax();
    REQUIRE( h.removeMax() == 50 );
    REQUIRE( h.removeMax() == 30 );
    REQUIRE( h.removeMax() == 20 );
    REQUIRE( h.removeMax() == 10 );
    REQUIRE( h.heapSize == 0 );
}



TEST_CASE( "stressTest" ) {
    MaxHeap<int> h;

    //Build vector with copies each of 0-99
    vector<int> v;
    for(int i = 0; i < 100; i++) {
        v.push_back(i);
        v.push_back(i);
    }

    std::random_shuffle(v.begin(), v.end());

    //Now add randomly ordered values to heap
    for(int i : v) {
        h.add(i);
    }

    INFO(h.toString());

    //Check them
    for(int i = 99; i >= 0; i--) {
        REQUIRE( h.removeMax() == i );
        REQUIRE( h.removeMax() == i );
    }
}

