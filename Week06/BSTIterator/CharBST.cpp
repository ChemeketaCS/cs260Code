#include "CharBST.h"

#include <iostream>
using namespace std;

///----------------------CON/DE STRUCTORS----------------------------
CharBST::CharBST() {
    root = nullptr;
}

CharBST::~CharBST() {
    //Destructor not provided - currently leaks all nodes
}

///------------------------toVector---------------------------

void vecBuilder(BSTNode<char>* curNode, vector<char>& theVec) {
    if(curNode == nullptr)
        return;

    vecBuilder(curNode->left, theVec);
    theVec.push_back(curNode->value);
    vecBuilder(curNode->right, theVec);
}

vector<char> CharBST::toVector() {
    vector<char> theVec;
    vecBuilder(root, theVec);
    return theVec;
}

///-----------------------Itarators----------------------------
CharBSTIterator CharBST::begin() {
    CharBSTIterator bIt;

    BSTNode<char>* current = root;
    while(current != nullptr) {
        bIt.positionStack.push_back(current);
        current = current->left;
    }

    return bIt;
}

CharBSTIterator CharBST::end() {
    return CharBSTIterator();
}
