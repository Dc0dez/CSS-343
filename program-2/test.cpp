// ------------------------------------------------ test.cpp -------------------------------------------------------

// Taggart Vowels, CSS343A

// Creation Date: 16 October 2024

// Date of Last Modification: 19 October 2024

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This file is used to thoroughly test the Binary Tree class called "BinTree". There are 5 phases that test
//			 every part of the program using asserts and terminal prints.

// -------------------------------------------------------------------------------------------------------------------- 

// Notes - No special algorithms are used, expected outputs are displayed, and 4/5 phases should print passed.

// Special Algorithms - None.

// --------------------------------------------------------------------------------------------------------------------

#include "bintree.h"
#include <iostream>
#include <assert.h>
#include <vector>

// ------------------------------------test1----------------------------------------------- 

// Description

// test1(BinTree &tree): Tests the ability to get the corrent height.
// preconditions: Assumes a valid tree was provided.
//				  Param tree: tree used for testing.

// postconditions: should produce "Passed test1" message.

// -------------------------------------------------------------------------------------------- 
void test1(BinTree &tree)
{
	assert(tree.getHeight("10") == 3);
	assert(tree.getHeight("5") == 2);
	assert(tree.getHeight("20") == 2);
	assert(tree.getHeight("3") == 1);
	assert(tree.getHeight("7") == 1);
	assert(tree.getHeight("15") == 1);
	assert(tree.getHeight("25") == 1);
	assert(tree.getHeight("100") == 0);
	cout << "Passed test1" << endl;
}

// ------------------------------------test2----------------------------------------------- 

// Description

// test2(BinTree &tree): Tests the copy construtor and assignment operator.
// preconditions: Assumes a valid tree was provided.
//				  Param tree: tree used for testing.

// postconditions: should produce "Passed test2" message.

// -------------------------------------------------------------------------------------------- 
void test2(BinTree &tree)
{
	BinTree copyTree = tree;
	BinTree assignmentTree;
	
	assert(assignmentTree.insert("1") == 1);
	assert(assignmentTree.insert("0") == 1);
	assert(assignmentTree.insert("2") == 1);
	assignmentTree = copyTree;

	assert(tree == copyTree);
	assert(copyTree == assignmentTree);

	assert(&tree != &copyTree 
			&& &copyTree != &assignmentTree 
			&& &assignmentTree != &tree);

	cout << "Passed test2" << endl;
}

// ------------------------------------test3----------------------------------------------- 

// Description

// test3(BinTree &tree): Tests that every object can be retrieved.
// preconditions: Assumes a valid tree was provided.
//				  Param tree: tree used for testing.

// postconditions: should produce "Passed test3" message.

// -------------------------------------------------------------------------------------------- 
void test3(BinTree &tree)
{
	Node* result = nullptr;
	
	assert(tree.retrieve("10", result) == 1);
	assert(result->data == "10");
	assert(tree.retrieve("5", result) == 1);
	assert(result->data == "5");
	assert(tree.retrieve("20", result) == 1);
	assert(result->data == "20");
	assert(tree.retrieve("3", result) == 1);
	assert(result->data == "3");
	assert(tree.retrieve("7", result) == 1);;
	assert(result->data == "7");
	assert(tree.retrieve("15", result) == 1);
	assert(result->data == "15");
	assert(tree.retrieve("25", result) == 1);
	assert(result->data == "25");
	assert(tree.retrieve("100", result) == 0);
	assert(result == nullptr);

	cout << "Passed test3" << endl;
}

// ------------------------------------test4----------------------------------------------- 

// Description

// test4(BinTree &tree): Tests comparision operators.
// preconditions: Assumes a valid tree was provided.
//				  Param tree: tree used for testing.

// postconditions: should produce "Passed test4" message.

// -------------------------------------------------------------------------------------------- 
void test4(BinTree &tree)
{
	BinTree equalTree;
	BinTree notEqualTree;
	assert(equalTree.insert("10") == 1);
	assert(equalTree.insert("5") == 1);
	assert(equalTree.insert("20") == 1);
	assert(equalTree.insert("3") == 1);
	assert(equalTree.insert("7") == 1);
	assert(equalTree.insert("15") == 1);
	assert(equalTree.insert("25") == 1);
	
	assert(equalTree == tree);
	assert(equalTree != notEqualTree);
	assert(notEqualTree.insert("1") == 1);
	assert(notEqualTree.insert("2") == 1);
	assert(notEqualTree.insert("3") == 1);
	assert(notEqualTree.insert("4") == 1);
	assert(notEqualTree.insert("5") == 1);
	assert(equalTree != notEqualTree);
	cout << "Passed test4" << endl;
}

// ------------------------------------test5----------------------------------------------- 

// Description

// test5(BinTree &tree): Tests tree to array and array to tree.
// preconditions: Assumes a valid tree was provided.
//				  Param tree: tree used for testing.

// postconditions: Two arrays should be printed in order. [3,5,7,15,20,25] && [1,2,3,4,5]

// -------------------------------------------------------------------------------------------- 
void test5(BinTree &tree)
{
	string arr[ARRAYSIZE];
	BinTree arrTree;

	// Empty Tree;
	arrTree.bstreeToArray(arr);
	assert(arr->empty());

	arrTree = tree;
	arrTree.bstreeToArray(arr);

	cout << "\nTree to array result: " << endl;
	cout << "Should print: 3,5,7,10,15,20,25" << endl;
	for (auto& x : arr) cout << x << " ";
	cout << endl;
	assert(arrTree.isEmpty());

	arrTree.arrayToBSTree(arr);
	assert(tree == arrTree);

	cout << "\nShould print: 1,2,3,4,5" << endl;
	string temp[ARRAYSIZE] = {"1","2","3","4","5"};
	arrTree.arrayToBSTree(temp);
	cout << arrTree << endl;
}

int main()
{
	BinTree tree;
	assert(tree.insert("10") == 1);
	assert(tree.insert("5") == 1);
	assert(tree.insert("20") == 1);
	assert(tree.insert("3") == 1);
	assert(tree.insert("7") == 1);
	assert(tree.insert("15") == 1);
	assert(tree.insert("25") == 1);
	assert(tree.insert("5") == 0);

	// Test printing trees
	cout << "Display Tree:" << endl;
	tree.displayTree();
	cout << "Sideways Print:" << endl;
	tree.displaySideways();
	cout << "Output Operator: " << tree << endl;

	test5(tree);
	test1(tree);
	test2(tree);
	test3(tree);
	test4(tree);
}