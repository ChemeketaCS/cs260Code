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

#include "Queue.h"
//#include "code.cpp"     //Your code in cpplab

using namespace std;

//Add test data to list.
//Built to take existing list to avoid using copy ctor or assignment
void addTestData(Queue<char>& q) {
    for(int i = 0; i < 6; i++)
        q.enqueue(static_cast<char>('A' + i));
}

TEST_CASE( "Enqueue1" ) {
    Queue<char> q;

    q.enqueue('A');
    INFO(q.toString());
    REQUIRE( q.start == 0 );
    REQUIRE( q.end == 1 );
    REQUIRE( q.list[q.start] == 'A' );
}

TEST_CASE( "Enqueue2" ) {
    Queue<char> q;

    q.enqueue('A');
    q.enqueue('B');

    INFO(q.toString());
    REQUIRE( q.start == 0 );
    REQUIRE( q.end == 2 );
    REQUIRE( q.list[q.start] == 'A' );
    REQUIRE( q.list[q.end - 1] == 'B' );
}

TEST_CASE( "Enqueue3" ) {
    Queue<char> q;

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');

    INFO(q.toString());
    REQUIRE( q.start == 0 );
    REQUIRE( q.end == 3 );
    REQUIRE( q.list[q.start] == 'A' );
    REQUIRE( q.list[q.end - 1] == 'C' );
}

TEST_CASE( "Dequeue1" ) {
    Queue<char> q;

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    char x = q.dequeue();

    INFO(q.toString());
    REQUIRE( q.start == 1 );
    REQUIRE( q.end == 3 );
    REQUIRE( x == 'A' );
}

TEST_CASE( "DequeueMultiple" ) {
    Queue<char> q;

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    char x = q.dequeue();
    char y = q.dequeue();
    char z = q.dequeue();

    INFO(q.toString());
    REQUIRE( x == 'A' );
    REQUIRE( y == 'B' );
    REQUIRE( z == 'C' );
}

TEST_CASE( "WrapEnd" ) {
    Queue<char> q;
    addTestData(q); //A B C D E F

    q.dequeue();
    q.dequeue();

    q.enqueue('G');
    q.enqueue('H');
    REQUIRE( q.end == 0 );
    q.enqueue('I');
    REQUIRE( q.end == 1 );

    INFO(q.toString());
    REQUIRE( q.list[0] == 'I' );
}

TEST_CASE( "WrapStart" ) {
    Queue<char> q;
    addTestData(q); //A B C D E F
    for(int i = 0; i < 6; i++)
        q.dequeue();
    q.enqueue('G');
    q.enqueue('H');
    q.enqueue('I');
    q.enqueue('J');

    for(int i = 0; i < 3; i++)
        q.dequeue();

    INFO(q.toString());
    REQUIRE( q.start == 1 );
    REQUIRE( q.end == 2 );
}

TEST_CASE( "Full" ) {
    Queue<char> q;
    addTestData(q); //A B C D E F

    INFO(q.toString());

    REQUIRE( q.full() == false );

    q.enqueue('G');
    REQUIRE( q.full() == true );

    q.dequeue();
    REQUIRE( q.full() == false );

    q.enqueue('H');
    REQUIRE( q.full() == true );
}


TEST_CASE( "Grow" ) {
    Queue<char> q;
    addTestData(q); //A B C D E F
    for(int i = 0; i < 20; i++)
        q.enqueue('A');

    INFO(q.toString());
    REQUIRE( q.dequeue() == 'A' );
    REQUIRE( q.dequeue() == 'B' );
    REQUIRE( q.dequeue() == 'C' );
    REQUIRE( q.dequeue() == 'D' );
    REQUIRE( q.dequeue() == 'E' );
    REQUIRE( q.dequeue() == 'F' );
    REQUIRE( q.dequeue() == 'A' );
}

TEST_CASE( "GrowAfterWrap" ) {
    Queue<char> q;
    addTestData(q); //A B C D E F
    for(int i = 0; i < 6; i++)
        q.dequeue();
    q.enqueue('G');
    q.enqueue('H');
    q.enqueue('I');
    q.enqueue('J');
    for(int i = 0; i < 20; i++)
        q.enqueue('A');

    INFO(q.toString());
    REQUIRE( q.dequeue() == 'G' );
    REQUIRE( q.dequeue() == 'H' );
    REQUIRE( q.dequeue() == 'I' );
    REQUIRE( q.dequeue() == 'J' );
    REQUIRE( q.dequeue() == 'A' );
}





