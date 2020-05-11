#include "CharBST.h"

#include <iostream>
using namespace std;

///----------------------CON/DE STRUCTORS----------------------------
CharBST::CharBST() {
    root = nullptr;
}

void deleteSubTree(BSTNode<char>* curNode) {
    //TODO - fixme
}

CharBST::~CharBST() {
    deleteSubTree(root);
    root = nullptr;
}

///----------------------Print----------------------------
///Nonmember helper function
string toStringHelper(BSTNode<char>* curNode) {
    if(curNode == nullptr)
        return "";

    string result = toStringHelper(curNode->left);
    result += to_string(curNode->value)+ " ";
    result += toStringHelper(curNode->right);

    return result;
}

string CharBST::toString() const {
    return toStringHelper(root);
}


///----------------------Search---------------------------

bool containsHelper(BSTNode<char>* curNode, char valToFind) {
    //TODO - fixme
    return false;
}

///recursive version
bool CharBST::containsRecursive(char valToFind) const {
    return containsHelper(root, valToFind);
}

///iterative version
bool CharBST::containsIterative(char valToFind) const {
    //TODO - fixme
    return false;
}

///----------------------insert---------------------------

BSTNode<char>* insertHelper(BSTNode<char>* curNode, char insertVal) {
    //TODO - fixme
}

void CharBST::insertRecursive(char insertVal) {
    root = insertHelper(root, insertVal);
}


void CharBST::insertIterative(char insertVal) {
    //TODO - fixme
}

