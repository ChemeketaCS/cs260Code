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

#include "LinkedList.h"
//#include "code.cpp"     //Your code in cpplab

using namespace std;

//Add test data to list.
//Built to take existing list to avoid using copy ctor or assignment
void buildTestIntList(LinkedList<int>& list) {
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
}


TEST_CASE( "LLIterator/Deref" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //10, 20, 30

    LinkedListIterator<int> location = test_list.begin();
    REQUIRE( *location == 10 );
}

TEST_CASE( "LLIterator/Increment" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //10, 20, 30

    LinkedListIterator<int> location = test_list.begin();
    REQUIRE( *location == 10 );
    ++location;
    REQUIRE( *location == 20 );
    ++location;
    REQUIRE( *location == 30 );
    ++location;
    REQUIRE( location == test_list.end() );
}

TEST_CASE( "LL/insertAfter" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //10, 20, 30

    LinkedListIterator<int> location = test_list.begin();
    ++location;
    test_list.insertAfter(location, 25);

    LinkedListIterator<int> location2 = test_list.begin();
    ++location2;
    REQUIRE( *location2 == 20 );
    ++location2;
    REQUIRE( *location2 == 25 );
    ++location2;
    REQUIRE( *location2 == 30 );
}





