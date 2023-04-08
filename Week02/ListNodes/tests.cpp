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

#include "Node.h"

//Declare functions we will build
Node<int>* buildList();
int getSecondValue(Node<int>* head);
int getTotalValue(Node<int>* head);
int countNodes(Node<int>* head);
int getLastValue(Node<int>* head);
void removeSecondValue(Node<int>* head);

//Prebuilt debugging helper function
void printList(Node<int>* start);

//Prebuilt cleanup function
void deleteList(Node<int>* start);

using namespace std;


TEST_CASE( "buildList" ) {
    Node<int>* start = buildList();
    REQUIRE( start->element == 10 );
    REQUIRE( start->next->element == 20 );
    REQUIRE( start->next->next->element == 30 );
    REQUIRE( start->next->next->next->element == 40 );

    deleteList(start);
}

TEST_CASE( "getSecondValue" ) {
    Node<int>* start = buildList();
    REQUIRE( getSecondValue(start) == 20 );

    //Remove first node
    Node<int>* toDelete = start;
    start = start->next;
    delete toDelete;

    REQUIRE( getSecondValue(start) == 30 );

    deleteList(start);
}

TEST_CASE( "countNodes" ) {
    Node<int>* start = buildList();
    REQUIRE( countNodes(start) == 4 );

    //Remove first node
    Node<int>* toDelete = start;
    start = start->next;
    delete toDelete;

    REQUIRE( countNodes(start) == 3 );

    REQUIRE( countNodes(nullptr) == 0 );

    deleteList(start);
}

TEST_CASE( "removeSecondValue" ) {
    Node<int>* start = buildList();

    removeSecondValue(start);
    REQUIRE( start->element == 10 );
    REQUIRE( start->next->element == 30 );
    REQUIRE( start->next->next->element == 40 );

    removeSecondValue(start);
    REQUIRE( start->element == 10 );
    REQUIRE( start->next->element == 40 );

    removeSecondValue(start);
    REQUIRE( start->element == 10 );
    REQUIRE( start->next == nullptr );

    delete start;
}


