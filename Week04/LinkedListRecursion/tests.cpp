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

#include "SimpleLinkedList.h"

using namespace std;

//Add test data to list.
//Built to take existing list to avoid using copy ctor or assignment
void buildTestIntList(SimpleLinkedList& list) {
    list.insertStart(30);
    list.insertStart(20);
    list.insertStart(10);
}

TEST_CASE( "LL/getTotal" ) {
    SimpleLinkedList test_list;
    cout << test_list.getTotal();
}

TEST_CASE( "LL/recursiveReverseToString" ) {
    SimpleLinkedList test_list;
    buildTestIntList(test_list);  //10, 20, 30

    string result = test_list.reverseToString();
    REQUIRE( result == "30 20 10" );
}

TEST_CASE( "LL/recursiveMax" ) {
    SimpleLinkedList test_list;
    test_list.insertStart(30);
    test_list.insertStart(40);
    test_list.insertStart(10);

    REQUIRE( test_list.getMaxValue() == 40 );

    test_list.insertStart(50);
    REQUIRE( test_list.getMaxValue() == 50 );
}

TEST_CASE( "LL/destruct" ) {

    int startNodeCount = ListNode::nodeCount;
    {
        SimpleLinkedList test_list;
        buildTestIntList(test_list);
        //test_list leaves scope and destructed
    }

    REQUIRE( ListNode::nodeCount - startNodeCount == 0 );
}
