#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>

using namespace std;

///Implementation in .h to make life easier... not good general design,
/// but easier for you to see everything at once

///Abstract struct
struct ExpressionNode
{
    ///get value of expression starting at this node
	virtual int evaluate() = 0;

    ///get printable representation
    virtual string toString() = 0;

	virtual ~ExpressionNode() {}
};


///Represents a single value
struct ValueNode : public ExpressionNode
{
    int value;

    ValueNode(int val) {
        value = val;
    }

	virtual int evaluate() { return value; }

    virtual string toString() {
        return std::to_string(value);
    }
};

///Represents s binary operator
struct BinaryOperatorNode : public ExpressionNode
{
    char operation;
    ExpressionNode* left;
    ExpressionNode* right;

    BinaryOperatorNode(char op) {
        operation = op;
        left = nullptr;
        right= nullptr;
    }

	virtual int evaluate() {
	    switch(operation) {
            case '*': return left->evaluate() * right->evaluate();
            case '/': return left->evaluate() / right->evaluate();
            case '%': return left->evaluate() % right->evaluate();
            case '+': return left->evaluate() + right->evaluate();
            case '-': return left->evaluate() - right->evaluate();
	    }
        cout << "Bad operation " << operation;
	    assert(0);
	    return 0; //never reach
    }

	virtual string toString() {
	    string s = "";
	    return s + operation;
    }

    virtual ~BinaryOperatorNode()  {
        if(left != nullptr) {
            delete left;
        }
        if(right != nullptr) {
            delete right;
        }
	}

};


#endif // EXPRESSIONNODE_H
