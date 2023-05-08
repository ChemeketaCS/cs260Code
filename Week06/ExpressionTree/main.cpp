#include <iostream>

#include "ExpressionNode.h"

using namespace std;

void printPreOrder(ExpressionNode* current) {
    //check if node is a BinaryOperator
    BinaryOperatorNode* currAsOpNode = dynamic_cast<BinaryOperatorNode*>(current);
    if(currAsOpNode != nullptr) {
        //print self, RecurseLeft, RecurseRight
        cout << currAsOpNode->toString() << " ";
        printPreOrder(currAsOpNode->left);
        printPreOrder(currAsOpNode->right);
    } else {
        //Must be a plain ValueNode, so just print
        cout << current->toString() << " ";
    }
}

void printPostOrder(ExpressionNode* current) {
    //check if node is a BinaryOperator
    BinaryOperatorNode* currAsOpNode = dynamic_cast<BinaryOperatorNode*>(current);
    if(currAsOpNode != nullptr) {
        //RecurseLeft, RecurseRight, print self
        printPostOrder(currAsOpNode->left);
        printPostOrder(currAsOpNode->right);
        cout << currAsOpNode->toString() << " ";
    } else {
        //Must be a plain ValueNode, so just print
        cout << current->toString() << " ";
    }
}

void printInOrder(ExpressionNode* current) {
    //check if node is a BinaryOperator
    BinaryOperatorNode* currAsOpNode = dynamic_cast<BinaryOperatorNode*>(current);
    if(currAsOpNode != nullptr) {
        cout << "( ";
        //RecurseLeft, print self, RecurseRight
        printInOrder(currAsOpNode->left);
        cout << currAsOpNode->toString() << " ";
        printInOrder(currAsOpNode->right);
        cout << ") ";
    } else {
        //Must be a plain ValueNode, so just print
        cout << current->toString() << " ";
    }
}

void printTree(ExpressionNode* current, string indent) {
    //Always print current node (with indentation)
    cout << indent << current->toString() << endl;

    //Try to turn curr into a pointer to a BinaryOperator
    BinaryOperatorNode* currAsOpNode = dynamic_cast<BinaryOperatorNode*>(current);
    if(currAsOpNode != nullptr) {
        //It worked - currAsOpNode points to a binary operator, recursively print children
        printTree(currAsOpNode->left, indent + "  ");
        printTree(currAsOpNode->right, indent + "  ");
    }
}


int main()
{
    ///---------------set up the tree--------------
    BinaryOperatorNode* root = new BinaryOperatorNode('*');
    BinaryOperatorNode* n1 = new BinaryOperatorNode('+');
    ValueNode* n2 = new ValueNode(7);
    ValueNode* n3 = new ValueNode(2);
    BinaryOperatorNode* n4 = new BinaryOperatorNode('-');
    ValueNode* n5 = new ValueNode(5);
    ValueNode* n6 = new ValueNode(3);

    root->left = n1;
    root->right = n4;
    n1->left = n2;
    n1->right = n6;
    n4->left = n5;
    n4->right = n3;

    cout << "-----------------------------------------------------\n";

    printTree( root, "");
    cout << "Expression evaluates to: " << root->evaluate() << endl;

    cout << "-----------------------------------------------------\n";



    ///--------------Traversals----------------
    cout << "InOrder:   ";
    printInOrder( root );
    cout << endl;

    cout << "PostOrder: ";
    printPostOrder( root );
    cout << endl;


    cout << "PreOrder:  ";
    printPreOrder( root );
    cout << endl;

    delete root;
}
