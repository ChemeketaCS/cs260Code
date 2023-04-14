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

#include "DoublyLinkedList.h"
//#include "code.cpp"     //Your code in cpplab

using namespace std;

TEST_CASE( "DLL/Constructor" ) {
    int startNodeCount = ListNode<int>::nodeCount;

    DoublyLinkedList<int> test_list;

    REQUIRE( test_list.length == 0 );
    REQUIRE( test_list.tail != nullptr );
    REQUIRE( test_list.head != nullptr );
    REQUIRE( test_list.tail->prev == test_list.head );
    REQUIRE( test_list.head->next == test_list.tail );
    REQUIRE( ListNode<int>::nodeCount - startNodeCount == 2 );           //dummies
}


TEST_CASE( "DLL/removeEnd" ) {
    //Requires working constructor!
    DoublyLinkedList<int> test_list;
    test_list.insertStart(40);
    test_list.insertStart(30);
    test_list.insertStart(20);
    test_list.insertStart(10);

    int startNodeCount = ListNode<int>::nodeCount;

    test_list.removeEnd();

    REQUIRE( test_list.length == 3 );
    REQUIRE( test_list.retrieveAt(0) == 10 );
    REQUIRE( test_list.retrieveAt(2) == 30 );
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 1 );

    test_list.removeEnd();
    test_list.removeEnd();

    REQUIRE( test_list.length == 1 );
    REQUIRE( test_list.retrieveAt(0) == 10 );
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 3 );

    test_list.removeEnd();

    REQUIRE( test_list.length == 0 );
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 4 );
}


TEST_CASE( "DLL/insertAt" ) {
    //Requires working constructor!
    DoublyLinkedList<int> test_list;

    int startNodeCount = ListNode<int>::nodeCount;

    test_list.insertAt(0, 30);

    REQUIRE( test_list.length == 1 );
    REQUIRE( test_list.retrieveAt(0) == 30 );
    REQUIRE( ListNode<int>::nodeCount - startNodeCount == 1 );

    test_list.insertAt(0, 10);

    REQUIRE( test_list.length == 2 );
    REQUIRE( test_list.retrieveAt(0) == 10 );
    REQUIRE( test_list.retrieveAt(1) == 30 );
    REQUIRE( ListNode<int>::nodeCount - startNodeCount == 2 );

    test_list.insertAt(1, 20);

    REQUIRE( test_list.length == 3 );
    REQUIRE( test_list.retrieveAt(0) == 10 );
    REQUIRE( test_list.retrieveAt(1) == 20 );
    REQUIRE( test_list.retrieveAt(2) == 30 );
    REQUIRE( ListNode<int>::nodeCount - startNodeCount == 3 );

    //Sanity check the dummies
    REQUIRE( test_list.tail->prev->data == 30 );
    REQUIRE( test_list.head->next->data == 10 );
}

