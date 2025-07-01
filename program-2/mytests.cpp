// ------------------------------------------------ mytests.cpp --------------------------------------------------------

// Dylan Nelson CSS 343 A

// Creation Date
// 10/18/24

// Date of Last Modification
// 10/19/24

// ---------------------------------------------------------------------------------------------------------------------

// File is used to test the functionality of all the methods in bintree.cpp

// --------------------------------------------------------------------------------------------------------------------- 

// Tests will correctly output expected values if the methods in bintree.cpp are structured correctly
// Tests check for proper addition of tree nodes; clearing of binary tree and tree to array; comparing trees; 
//      tree structure; creating a tree from and array;
//		and if the tree nodes contain specific values for the original tree, copied tree, and assignment tree

// ---------------------------------------------------------------------------------------------------------------------


#include "bintree.h"
#include <iostream>

// ------------------------------------isArrayEmpty----------------------------------------------- 

// isArrayEmpty: checks if array is empty

// preconditions: takes const string data[] and int size as parameters
//				  a valid array is intialized

// postconditions: returns false if data exists and true if it does not

// -----------------------------------------------------------------------------------------------

bool isArrayEmpty(const string data[], int size) {
    for (int i = 0; i < size; i++) {
        if (data [i] != "") {
            return false;
        }
    }
    return true; 
}

int main()
{

    // inializes empty tree
	BinTree tree; 
    
    // fills tree with data
	tree.insert("10");
	tree.insert("5");
	tree.insert("7");
	tree.insert("16");
	tree.insert("22");
	tree.insert("27");
	tree.insert("4");
	tree.insert("1");
	tree.insert("13");

    BinTree emptyTree;

    // checks if empty tree is equal to filled tree
    cout << "Check if empty tree is equal to tree with nodes" << endl;
    cout << "Are they same?  " << ((emptyTree == tree) ? " yes " : " no") << endl;

    cout << "Are they different?  " << ((emptyTree != tree) ? " yes " : " no")
         << endl;

    cout << endl;

    // prints out tree
    cout << "Display tree: " << endl;
    tree.displayTree();
    cout<< "Display sideways tree: " << endl;
    tree.displaySideways();

	cout << "Output Operator: " << tree << endl;
    cout<< endl;

    // creates a copy of the tree
	BinTree copyTree = tree;

    // checks if copy is equal to the original
    cout << "Check if copy tree is equal to original tree" << endl;
    cout << "Are they same?  " << ((copyTree == tree) ? " yes " : " no") << endl;

    cout << "Are they different?  " << ((copyTree != tree) ? " yes " : " no")
         << endl;
    cout<< endl;

    copyTree.insert("12");

    // checks if copy is equal to original after adding a value
    cout << "Check if copy tree is equal to original tree after inserting 12" << endl;
    cout << "Are they same?  " << ((copyTree == tree) ? " yes " : " no") << endl;

    cout << "Are they different?  " << ((copyTree != tree) ? " yes " : " no")
         << endl;
    cout<< endl;

    // checks that assignment tree is correctly destroyed and recreated if it is different from copy tree
    BinTree assignmentTree;
    assignmentTree.insert("11");
    assignmentTree.insert("0");
    assignmentTree.insert("2");
    assignmentTree = copyTree;

    // prints out copy and assignment trees
    cout << "Copy tree: " << copyTree << endl;
    cout<< "Display tree: " << endl;
    copyTree.displayTree();
    cout<< "Display sideways tree: " << endl;
    copyTree.displaySideways();
    cout << "Assignment tree: " << assignmentTree << endl;
    cout<< "Display tree: " << endl;
    assignmentTree.displayTree();
    cout<< "Display sideways tree: " << endl;
    assignmentTree.displaySideways();
    

    // initliazes array and array tree
    string array[ARRAYSIZE];
    BinTree arrayTree;
    
    arrayTree = tree;
    arrayTree.bstreeToArray(array);
    cout<< endl;
    
    // outputs contents of the array
    cout << "Array: " << endl;
    for (const string &s : array){
        cout << s << " ";
    }
    
    // checks if the tree and array are empty
    cout<< endl;
    bool empty = arrayTree.isEmpty();
	
    cout << "Tree is empty" << (empty ? ": Yes" : ": No") << endl;
    empty = isArrayEmpty(array, ARRAYSIZE);
    cout << "Array is empty" << (empty ? ": Yes" : ": No") << endl;
    
    // builds balanced tree with array values
    cout << endl;
	arrayTree.arrayToBSTree(array);
    
    cout<< "Display balanced tree: " << endl;
    arrayTree.displayTree();
    cout<< "Display balanced sideways tree: " << endl;
	arrayTree.displaySideways();

    cout << endl;

    // checks if the tree and array are empty
    empty = arrayTree.isEmpty();
    cout << "Tree is empty" << (empty ? ": Yes" : ": No") << endl;
    
	empty = isArrayEmpty(array, ARRAYSIZE);
    cout << "Array is empty" << (empty ? ": Yes" : ": No") << endl;

	return 0;
}
