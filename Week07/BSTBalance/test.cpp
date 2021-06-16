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

#include "CharBST.h"
//#include "code.cpp"     //Your code in cpplab

//Declare  functions from the .cpp file so that we can directly test them
BSTNode<char>* rotateLeft(BSTNode<char>* parent);
BSTNode<char>* rotateRight(BSTNode<char>* parent);
int getHeight(BSTNode<char>* node);
int getBalance(BSTNode<char>* node);
int getSubtreeSize(BSTNode<char>* node);

using namespace std;

/* Adds test data to produce this tree:
 *         _G_
 *        /   \
 *       C     P
 *      / \   / \
 *     B   F J   Y
 *            \
 *             M
 */

void insertTestData(CharBST& c) {
    c.root = nullptr;   //remove (and leak!!!) any existing nodes

    c.root = new BSTNode<char>('G');

    c.root->left = new BSTNode<char>('C');
    c.root->left->left = new BSTNode<char>('B');
    c.root->left->right = new BSTNode<char>('F');

    c.root->right = new BSTNode<char>('P');
    c.root->right->right = new BSTNode<char>('Y');
    c.root->right->left = new BSTNode<char>('J');
    c.root->right->left->right = new BSTNode<char>('M');
}


TEST_CASE( "RotateRightAtC" ) {
    CharBST bst;
    insertTestData(bst);

    BSTNode<char>* target = bst.root->left;

    BSTNode<char>* newParent = rotateRight(target);

    REQUIRE( newParent->value == 'B' );
    REQUIRE( newParent->right->value == 'C' );
    REQUIRE( newParent->right->left == nullptr );
}

TEST_CASE( "RotateRightAtG" ) {
    CharBST bst;
    insertTestData(bst);

    BSTNode<char>* target = bst.root;

    BSTNode<char>* newParent = rotateRight(target);

    REQUIRE( newParent->value == 'C' );
    REQUIRE( newParent->right->value == 'G' );
    REQUIRE( newParent->right->left->value == 'F' );
}


TEST_CASE( "RotateLAtC" ) {
    CharBST bst;
    insertTestData(bst);

    BSTNode<char>* target = bst.root->left;

    BSTNode<char>* newParent = rotateLeft(target);

    REQUIRE( newParent->value == 'F' );
    REQUIRE( newParent->left->value == 'C' );
    REQUIRE( newParent->left->right == nullptr );
}

TEST_CASE( "RotateRightAtG" ) {
    CharBST bst;
    insertTestData(bst);

    BSTNode<char>* target = bst.root;

    BSTNode<char>* newParent = rotateLeft(target);

    REQUIRE( newParent->value == 'P' );
    REQUIRE( newParent->left->value == 'G' );
    REQUIRE( newParent->left->right->value == 'J' );
}


TEST_CASE( "Size" ) {
    CharBST bst;
    insertTestData(bst);

    int FSize = getSubtreeSize(bst.root->left->right);
    REQUIRE( FSize == 1 );

    int JSize = getSubtreeSize(bst.root->right->left);
    REQUIRE( JSize == 2 );

    int fullSize = getSubtreeSize(bst.root);
    REQUIRE( fullSize == 8 );
}


TEST_CASE( "Height" ) {
    CharBST bst;
    insertTestData(bst);

    int FHeight = getHeight(bst.root->left->right);
    REQUIRE( FHeight == 0 );

    int JHeight = getHeight(bst.root->right->left);
    REQUIRE( JHeight == 1 );

    int fullHeight = getHeight(bst.root);
    REQUIRE( fullHeight == 3 );
}


TEST_CASE( "Balance" ) {
    CharBST bst;
    insertTestData(bst);

    int FBal = getBalance(bst.root->left->right);
    REQUIRE( FBal == 0 );

    int JBal = getBalance(bst.root->right->left);
    REQUIRE( JBal == 1 );

    int PBal = getBalance(bst.root->right);
    REQUIRE( PBal == -1 );

    int fullBal = getBalance(bst.root);
    REQUIRE( fullBal== 1 );
}
