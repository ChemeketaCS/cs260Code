#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cassert>

#include "CharBST.h"
#include "CharBSTIterator.h"

using namespace std;

//Forward declare function to set up test tree
void insertTestData(CharBST& c);


int main() {
    CharBST myBST;
    insertTestData(myBST);

    cout << "The tree as a vector: ";
    vector<char> myList = myBST.toVector();
    for(char c : myList)
        cout << c << " ";
    cout << endl;

    cout << "Iterating through the tree with an iterator: " << endl;
    for(auto it = myBST.begin(); it != myBST.end(); ++it) {
        cout << "Current location " << *it << " iterator stack: ";
        it.printDebug();
        cout << endl;
    }

}



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
