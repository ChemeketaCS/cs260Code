#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <ctime>
#include "CharBST.h"
#include "BSTNodePrettyPrint.h"

using namespace std;



template<class T>
BSTNode<T>* rotateLeft(BSTNode<T>* parent);

template<class T>
BSTNode<T>* rotateRight(BSTNode<T>* parent);


void testRotateLeft();
void testRotateRight();
void testRotateBoth();



int main()
{
    testRotateLeft();
    testRotateRight();
    testRotateBoth();

    return 0;
}


template<class T>
BSTNode<T>* rotateLeft (BSTNode<T>* parent) {
    ///TODO - make C pointer to child, do magic, return new parent
    return nullptr;
}

template<class T>
BSTNode<T>* rotateRight (BSTNode<T>* parent) {
    ///TODO - make C pointer to child, do magic, return new parent
    return nullptr;
}


void testRotateLeft() {
    CharBST myBST;
    myBST.insertFakeData();

    //print original tree
    printPretty(myBST.root,1,0,cout);
    cout << endl << "Rotating " << myBST.root->right->value << endl;

    //set root to result of rotating root left
    myBST.root = rotateLeft(myBST.root);

    //print new tree
    printPretty(myBST.root,1,0,cout);

    cout << endl;
    cout << "-----------------------------------------" << endl;
}


void testRotateRight() {
    CharBST myBST;
    myBST.insertFakeData();

    //print original tree
    printPretty(myBST.root,1,0,cout);
    cout << endl << "Rotating " << myBST.root->left->value << endl;

    //set root to result of rotating root left
    myBST.root = rotateRight(myBST.root);

    //print new tree
    printPretty(myBST.root,1,0,cout);

    cout << endl;
    cout << "-----------------------------------------" << endl;
}


void testRotateBoth() {
    CharBST myBST;
    myBST.insertFakeData();

    //print original tree
    cout << "Double rotation to get J to root:" << endl;
    printPretty(myBST.root,1,0,cout);
    cout << endl << "Rotating " << myBST.root->right->left->value << endl;
    cout << endl << "...then " << myBST.root->right->value << endl;

    //set right child to result of rotating right child right
    myBST.root->right = rotateRight(myBST.root->right);

    //printPretty(myBST.root,1,0,cout);

    //set root to result of rotate root left
    myBST.root = rotateLeft(myBST.root);

    //printPretty(myBST.root,1,0,cout);

    cout << endl;
    cout << "-----------------------------------------" << endl;
}


