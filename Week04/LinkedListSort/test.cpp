//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
//#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "LinkedList.h"
//#include "code.cpp"     //Your code in cpplab

using namespace std;

//Add test data to list.
//Built to take existing list to avoid using copy ctor or assignment
void buildTestIntList(LinkedList<int>& list) {
    list.insertEnd(5);
    list.insertEnd(6);
    list.insertEnd(2);
    list.insertEnd(4);
}

TEST_CASE( "LL/Split" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //5, 6, 2, 4

    int startNodeCount = ListNode<int>::nodeCount;

    LinkedList<int> second_half = test_list.sliceInHalf();

    REQUIRE( test_list.length == 2 );
    REQUIRE( second_half.length == 2 );

    REQUIRE( test_list.tail->data == 6 );
    REQUIRE( test_list.tail->next == nullptr );

    REQUIRE( second_half.head->data == 2 );
    REQUIRE( second_half.tail->data == 4 );

    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 0 );
}

TEST_CASE( "LL/SplitLonger" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);
    test_list.insertEnd(50);
    test_list.insertEnd(50);  //5, 6, 2, 4, 50, 50

    LinkedList<int> second_half = test_list.sliceInHalf();

    REQUIRE( test_list.length == 3 );
    REQUIRE( second_half.length == 3 );

    REQUIRE( test_list.tail->data == 2 );
    REQUIRE( test_list.tail->next == nullptr );

    REQUIRE( second_half.head->data == 4 );
    REQUIRE( second_half.tail->data == 50 );
}

TEST_CASE( "LL/SplitOddSize" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);
    test_list.insertEnd(50);  //5, 6, 2, 4, 50

    LinkedList<int> second_half = test_list.sliceInHalf();

    REQUIRE( test_list.length == 2 );
    REQUIRE( second_half.length == 3 );

    REQUIRE( test_list.tail->data == 6 );
    REQUIRE( test_list.tail->next == nullptr );

    REQUIRE( second_half.head->data == 2 );
    REQUIRE( second_half.tail->data == 50 );
}

TEST_CASE( "LL/StealAllOf" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list); //5, 6, 2, 4

    LinkedList<int> test_list2;
    test_list2.stealContents(test_list);

    REQUIRE( test_list2.head->data == 5 );
    REQUIRE( test_list2.tail->data == 4 );

    REQUIRE( test_list.head == nullptr );
    REQUIRE( test_list.tail == nullptr );

    REQUIRE( test_list.length == 0 );
    REQUIRE( test_list2.length == 4 );
}

TEST_CASE( "LL/Merge" ) {
    LinkedList<int> test_list;
    test_list.insertEnd(10);
    test_list.insertEnd(15);
    LinkedList<int> test_list2;
    test_list2.insertEnd(5);
    test_list2.insertEnd(20);

    int startNodeCount = ListNode<int>::nodeCount;

    test_list.mergeIn(test_list2);

    REQUIRE( test_list.length == 4 );
    REQUIRE( test_list2.length == 0 );

    REQUIRE( test_list.retrieveAt(0) == 5 );
    REQUIRE( test_list.retrieveAt(1) == 10 );
    REQUIRE( test_list.retrieveAt(2) == 15 );
    REQUIRE( test_list.retrieveAt(3) == 20 );

    REQUIRE( test_list2.head == nullptr );
    REQUIRE( test_list2.tail == nullptr );

    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 0 );
}

TEST_CASE( "LL/Merge2" ) {
    //multiple items from list 2 at end
    LinkedList<int> test_list;
    test_list.insertEnd(5);
    test_list.insertEnd(10);
    LinkedList<int> test_list2;
    test_list2.insertEnd(15);
    test_list2.insertEnd(20);
    test_list2.insertEnd(25);

    int startNodeCount = ListNode<int>::nodeCount;

    test_list.mergeIn(test_list2);

    REQUIRE( test_list.length == 5 );
    REQUIRE( test_list2.length == 0 );

    REQUIRE( test_list.retrieveAt(0) == 5 );
    REQUIRE( test_list.retrieveAt(1) == 10 );
    REQUIRE( test_list.retrieveAt(2) == 15 );
    REQUIRE( test_list.retrieveAt(3) == 20 );
    REQUIRE( test_list.retrieveAt(4) == 25 );

    REQUIRE( test_list2.head == nullptr );
    REQUIRE( test_list2.tail == nullptr );

    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 0 );
}

TEST_CASE( "LL/Merge3" ) {
    //multiple items from list 1 at end
    LinkedList<int> test_list;
    test_list.insertEnd(15);
    test_list.insertEnd(20);
    test_list.insertEnd(25);
    LinkedList<int> test_list2;
    test_list2.insertEnd(5);
    test_list2.insertEnd(10);

    int startNodeCount = ListNode<int>::nodeCount;

    test_list.mergeIn(test_list2);

    REQUIRE( test_list.length == 5 );
    REQUIRE( test_list2.length == 0 );

    REQUIRE( test_list.retrieveAt(0) == 5 );
    REQUIRE( test_list.retrieveAt(1) == 10 );
    REQUIRE( test_list.retrieveAt(2) == 15 );
    REQUIRE( test_list.retrieveAt(3) == 20 );
    REQUIRE( test_list.retrieveAt(4) == 25 );

    REQUIRE( test_list2.head == nullptr );
    REQUIRE( test_list2.tail == nullptr );

    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 0 );
}
