// ------------------------------------------------ driver.cpp --------------------------------------------------------

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
//		the height of the tree; retreiving node values; sstream; ostream; creating a tree from an array;
//      tree structure; and if the tree nodes contain specific values for the original tree, copied tree, and assignment tree

// ---------------------------------------------------------------------------------------------------------------------

#include "bintree.h"
#include <fstream>
#include <iostream>
#include <cctype>

using namespace std;


void buildTree(BinTree &T, ifstream &infile) {
  string s;

  for (;;) {
    infile >> s;
    //s=trim(s);
    // cout << s << ' ';
    if (s == "$$")
      break; // at end of one line
    if (infile.eof())
      break;         // no more lines of data
    string data = s; // data takes a string
    // would do a setData if there were more than a string

    bool success = T.insert(s);
  }
}

void printArray(string a[]) {
  for (int i = 0; i < ARRAYSIZE; i++) {
	if (!a[i].empty())
      cout << a[i] << ' ';
  }
  cout << endl;
}

int main() {

  // Test the fileread method

  ifstream infile("inputdata.txt");
  if (!infile) {
    cout << "File could not be opened." << endl;
    return 1;
  }

  cout << "Reading nodes from a file" << endl;

  while (!infile.eof()) {
    cout << "------------------------------" << endl;

    BinTree filetree;
    buildTree(filetree, infile);
    // Testing sideway print
    cout << "Sideway print: " << endl;

    filetree.displaySideways();

    cout << "Display tree: " << endl;

    filetree.displayTree();

    cout << "Inorder: " << filetree << endl;
    // test getHeight and retrieve (You can change the data to test)
    cout << "Test retrieve and getHeight" << endl;
    string testnode = "18";
    Node *addr;
    bool found = filetree.retrieve(testnode, addr);
    cout << "Retrieve " << testnode << (found ? ": found" : ": not found")
         << endl;
    if (found)
      cout << "Node address = " << addr << endl;

    cout << "Height of node " << testnode << " is "
         << filetree.getHeight(testnode) << endl;

    BinTree copytree(filetree);
    cout << "Copy Tree: " << copytree << endl;

    BinTree T = filetree;

    cout << "Assign Tree: " << T << endl;

    cout << "Are they same?  " << ((copytree == T) ? " yes " : " no") << endl;

    cout << "Are they different?  " << ((copytree != T) ? " yes " : " no")
         << endl;
  

  	cout << "BST to Array" << endl;

  	string ndarray[ARRAYSIZE];

    //Note that bstreeToArray empty the original filetree. Therefore, we need to copy the filetree to a new tree before calling this if want to keep the original tree.

	BinTree original (filetree);

	filetree.bstreeToArray(ndarray);
	printArray(ndarray);


	cout << "Array to BST: should balance the tree" << endl;

	filetree.arrayToBSTree(ndarray);
	filetree.displaySideways();
	filetree.displayTree();

	cout<<"Compare the original tree and recovered tree"<<endl;

	cout << "Are they same?  " << ((original == filetree) ? " yes " : " no")
		<< endl;

	cout << "Are they different?  " << ((original != filetree) ? " yes " : " no")
		<< endl;
}

return 0;
}
