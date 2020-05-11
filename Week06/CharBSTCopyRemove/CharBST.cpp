#include "CharBST.h"

#include <iostream>
#include <stdexcept>
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

//Helper used by copy ctor and assignment operator
BSTNode<char>* copySubTree(BSTNode<char>* currentNode) {
    //TODO - FIXME
    return nullptr;
}


CharBST::CharBST(const CharBST& other) {
    root = copySubTree(other.root);
}

CharBST& CharBST::operator=(const CharBST& other) {
    if(this != &other) {
        //remove any existing nodes
        deleteSubTree(root);
        //copying nodes of other tree
        root = copySubTree(other.root);
    }
    return *this;
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



///----------------------RemoveSmallest---------------------------

//Recursive function to remove smallest value starting from indicated node
BSTNode<char>* removeSmallestHelper(BSTNode<char>* curNode) {
    //TODO - FIXME - See worksheet
}

void CharBST::removeSmallest() {
    if(root != nullptr)
        root = removeSmallestHelper(root);
}


///----------------------Smallest---------------------------

//Recursive function to remove smallest value starting from indicated node
char smallestValueFrom(BSTNode<char>* curNode)
{
    //TODO - FIXME - See worksheet
    return '?';
}


///----------------------Removal---------------------------
///Helper function for remove - chains down, until it finds node to
/// remove. Removes that node and repairs pointers on way back up
BSTNode<char>* removeHelper(BSTNode<char>* curNode, char valToRemove) {
    if(curNode == nullptr) {
        return nullptr;     //Value not in tree
    }
    else if(valToRemove < curNode->value) {
        curNode->left = removeHelper(curNode->left, valToRemove);
    }
    else if(curNode->value < valToRemove) {
        //set right child to the result of removing the value from the right subtree
    }
    else {  //Found the value to remove

        //TODO

        //Case 0: No children (subcase of 1)
        //          Delete & return nullptr

        //Case 1: No right child
        //          Delete current and return left child

        //Case 2: No left child
        //          Delete current and return right child

        //Case 3: Two children
        //          Replace current's value with smallest value in right subtree
        //          Then set right child to result of removing that value from right subtree

    }

    return curNode;  //This node still exists. Return it back to caller.
}

void CharBST::remove(char value) {
    //new root is root that results from doing removeHelper
    root = removeHelper(root, value);
}




bool CharBST::isEmpty() {
    return root == nullptr;
}

