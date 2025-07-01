// ------------------------------------------------ bintree.h ----------------------------------------------------------

// Dylan Nelson CSS 343 A

// Creation Date
// 10/12/24

// Date of Last Modification
// 10/19/24

// ---------------------------------------------------------------------------------------------------------------------

// This file defines methods and variables to be implemented in bintree.cpp

// ---------------------------------------------------------------------------------------------------------------------

// No assumptions or special algorithms implemented in this file, file is included in bintree.cpp

// ---------------------------------------------------------------------------------------------------------------------
#pragma once

#include <iostream> //input and output
#include <sstream>
#include <string>
using namespace std;

const int ARRAYSIZE = 100;

// BST Node contains pointer for left, right, and data
struct Node
{
	string data;
	Node *left;
	Node *right;
};

class BinTree
{

	// Overloaded << : prints BinTree in correct structure

	friend ostream &operator<<(ostream &os, const BinTree &tree);

public:
	// Constructors
	BinTree();
	BinTree(const BinTree &rhs);

	// Desctructor
	virtual ~BinTree();

	// required public methods
	bool isEmpty() const; // check if tree is empty

	// retrieve the pointer of the node of given data
	bool retrieve(const string &data, Node *&treeNode) const;

	bool insert(const string &data); // insert node with the node data

	// displays the tree in pre-order, provide prefix (Root, L--, R--)
	void displayTree() const;

	void displaySideways() const; // displays the tree sidways

	// get height of a node starting from leaf (= 1)
	int getHeight(const string &data) const;

	// Overload operators
	// -- Assignment Operator
	BinTree &operator=(const BinTree &rhs); // this = rhs
	// -- Comparison Operators
	bool operator==(const BinTree &rhs) const; // this == rhs
	bool operator!=(const BinTree &rhs) const; // this != rhs

	// Miscellaneous Functions
	void bstreeToArray(string data[]);
	void arrayToBSTree(string data[]);

private:
	Node *root; // Points to the root of the BST

	// Private methods
	void copyNode(Node *&treeNode1, Node *treeNode2);
	void clear(Node *&treeNode);
	Node *retrieveNode(Node *treeNode, const string &data) const;
	bool insertStringNode(Node *&treeNode, const string &data);
	bool insertNumNode(Node *&treeNode, const string &data);
	bool isNum(const string &data);
	double convertString(const string &data);
	void printTree(Node *treeNode, int depth, const string &prefix) const;
	void printSidewaysTree(Node *treeNode, int space) const;
	int treeHeight(Node *treeNode) const;
	void osHelper(Node *treeNode, ostream &os) const;
	bool checkEqual(Node *treeNode1, Node *treeNode2) const;
	int treeToArrayHelper(Node *treeNode, string data[], int i);
	Node *arrayToTreeHelper(string data[], int start, int end);
};
