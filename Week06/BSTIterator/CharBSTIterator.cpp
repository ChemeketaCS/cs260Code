
#include <iostream>
#include "CharBSTIterator.h"

using namespace std;

CharBSTIterator::CharBSTIterator()
{
    //Add a nullptr to mark the end of the stack
    positionStack.push_back(nullptr);
}

void CharBSTIterator::printDebug()
{
    std::cout << "Top => ";  //end
    for(auto i = positionStack.size() - 1; i >= 1; i--) {
        BSTNode<char>* current = positionStack[i];
        std::cout << current->value << " ";
    }
    std::cout << "[END]";  //end
}

//Compare two iterators with ==
bool CharBSTIterator::operator==(const CharBSTIterator& other) const
{
    return positionStack.back() == other.positionStack.back();
}

//Compare two iterators with !=
bool CharBSTIterator::operator!=(const CharBSTIterator& other) const
{
    return positionStack.back() != other.positionStack.back();
}

//Dereference iterator to retrieve data in current node
// return reference to allow modification
char& CharBSTIterator::operator*()
{
    return positionStack.back()->value;
}

//Advance iterator position by one
void CharBSTIterator::operator++()
{
    //remove top pointer from stack
    BSTNode<char>* oldNode = positionStack.back();
    positionStack.pop_back();

    //if it has a right child, go left from it as far as you can pushing pointers
    BSTNode<char>* current = oldNode->right;
    while(current != nullptr) {
        positionStack.push_back(current);
        current = current->left;
    }
}

