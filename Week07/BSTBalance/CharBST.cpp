#include "CharBST.h"

#include <iostream>
#include <vector>
using namespace std;

///----------------------CON/DE STRUCTORS----------------------------
CharBST::CharBST() {
    root = nullptr;
}

//recursively delete nodes starting from a given node
void CharBST::deleteSubTree(BSTNode<char>* startNode) {
    if(startNode == nullptr)
        return;
    deleteSubTree(startNode->left);
    deleteSubTree(startNode->right);
    delete startNode;
}

CharBST::~CharBST() {
    deleteSubTree(root);
}


///----------------------Print----------------------------
///Nonmember helper function
void printHelper(BSTNode<char>* curNode) {
    if(curNode == nullptr)
        return;

    printHelper(curNode->left);
    cout << curNode->value << " ";
    printHelper(curNode->right);
}

void CharBST::print() {
    printHelper(root);
}

///--------------------Rotations--------------------------

BSTNode<char>* rotateLeft(BSTNode<char>* parent) {
    //TODO - fixme!
    return nullptr;
}

BSTNode<char>* rotateRight(BSTNode<char>* parent) {
    //TODO - fixme!
    return nullptr;
}

///-------------------Height/Size-------------------------

int getHeight(BSTNode<char>* node) {
    //TODO - fixme!
    return 0;
}

int getBalance(BSTNode<char>* node) {
    //TODO - fixme!
    return 0;
}

int getSubtreeSize(BSTNode<char>* node) {
    //TODO - fixme!
    return 0;
}

