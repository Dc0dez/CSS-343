// ------------------------------------------------ bintree.cpp --------------------------------------------------------

// Dylan Nelson CSS 343 A

// Creation Date
// 10/12/24

// Date of Last Modification
// 10/19/24

// ---------------------------------------------------------------------------------------------------------------------

// File implements declared methods in bintree.h 

// --------------------------------------------------------------------------------------------------------------------- 

// File is expected to implement methods and functions from bintree.h to create a binary search tree 
//      from string values, a sorted array from the binary search tree, 
//      and a balanced binary search tree from the sorted array
//
// Used special algorithm to balance the binary search tree

// ---------------------------------------------------------------------------------------------------------------------

#include "bintree.h"

// ------------------------------------BinTree---------------------------------------------------- 

// BinTree: constructs binary search tree with null root node

// preconditions: assumes constructor will run when object is initialized 

// postconditions: if object is initialized, creates an empty binary search tree with null root node

// -----------------------------------------------------------------------------------------------

BinTree::BinTree() {
    root = nullptr;
}

// ------------------------------------BinTree---------------------------------------------------- 

// BinTree: constructs a deep copy of the binary search tree

// preconditions: takes const BinTree &rhs as a parameter
//                assumes copy constructor will run when object is copied 

// postconditions: generates a deep copy of rhs using recursive call to copyNode 
//                 copy tree is generated in the same structure as rhs

// -----------------------------------------------------------------------------------------------

BinTree::BinTree(const BinTree &rhs) {
    if (rhs.root == nullptr) {
        root = nullptr;
        return;
    }
    copyNode(root, rhs.root);
}

// ------------------------------------copyNode---------------------------------------------------- 

// copyNode: recursively copies the binary search tree

// preconditions: takes Node *&treeNode1 and Node *treeNode2 as parameters
//				  must be called by parent method or recursively called 

// postconditions: deep copies treeNode2 into treeNode1

// -----------------------------------------------------------------------------------------------

void BinTree::copyNode(Node *&treeNode1, Node *treeNode2) {
    if (treeNode2 == nullptr) {
        treeNode1 = nullptr;
        return;
    }
    treeNode1 = new Node{treeNode2->data, nullptr, nullptr};
    copyNode(treeNode1->left, treeNode2->left);
    copyNode(treeNode1->right, treeNode2->right);
}

// ------------------------------------~BinTree---------------------------------------------------- 

// ~BinTree: deletes the binary search tree and deallocates memory 

// preconditions: a valid binary search tree is initialized   

// postconditions: all dynamically allocated memory for the tree nodes, including the root, is deallocated

// ------------------------------------------------------------------------------------------------

BinTree::~BinTree(){
    clear(root);
}

// ------------------------------------clear--------------------------------------------------- 

// clear: recursively removes all nodes from the binary search tree

// preconditions: takes Node *&treeNode as a parameter
//				  must be called by parent method or recursively called

// postconditions: if binary search tree contains nodes with elements, all nodes in the tree are deleted using 
//                 post-order traveral          

// --------------------------------------------------------------------------------------------

void BinTree::clear(Node *&treeNode) {
    if (treeNode == nullptr) {
        return;
    }
    clear(treeNode->left);
    clear(treeNode->right);
    delete treeNode;
    treeNode = nullptr;
}

// ------------------------------------isEmpty----------------------------------------------- 

// isEmpty: checks if the binary search tree is empty

// preconditions: a valid binary search tree is initialized  

// postconditions: returns true if the binary search tree contains no elements

// ------------------------------------------------------------------------------------------

bool BinTree::isEmpty() const {
    return root == nullptr; 
}

// ------------------------------------retrieve--------------------------------------------------- 

// retrieve: recursively calls retrieveNode to retrieve the node pointer of the target value

// preconditions: a valid binary search tree is intialized, 
//				  method takes string data and node treeNode parameters

// postconditions: if the target value exists in the binary search tree, value is retrieved and method returns true 

// -----------------------------------------------------------------------------------------------

bool BinTree::retrieve(const string &data, Node *&treeNode) const {
    if (isEmpty()) {
        return false;
    }
    treeNode = retrieveNode(root, data);
    return treeNode != nullptr;
}

// ------------------------------------retrieveNode-------------------------------------------------

// retrieveNode: recursively traverses the binary search tree and returns the target value when found

// preconditions: a valid binary search tree is intialized, 
//				  method takes string &data and Node *treeNode parameters
//                must be called by parent method or recursively called 

// postconditions: if the target value exists in the binary search tree, value is retrieved

// -----------------------------------------------------------------------------------------------

Node *BinTree::retrieveNode(Node *treeNode, const string &data) const {
    if (treeNode == nullptr) {
        return nullptr;
    }
    if (treeNode->data == data) {
        return treeNode;
    }
	
    Node *val = retrieveNode(treeNode->left, data);
    if (val != nullptr) {
        return val;
    }
    return retrieveNode(treeNode->right, data);
}

// ------------------------------------insert--------------------------------------------------- 

// insert: inserts nodes containing non-duplicate values into the binary search tree

// preconditions: a valid binary search tree is intialized
//				  method takes const string &data as a parameter   

// postconditions: if data is not currently in the tree, places a new node containing 
//                 the value into the tree

// ---------------------------------------------------------------------------------------------

bool BinTree::insert(const string &data) { 
    if (!isNum(data)) {
        return insertStringNode(root, data);
    }
    return insertNumNode(root, data);
}

// ------------------------------------insertString--------------------------------------------------- 

// insertString: inserts non-duplicate string value into the binary search tree

// preconditions: a valid binary search tree is intialized 
//				  method takes 'const string &data' and Node *&treeNode as parameters
//          	  must be called by parent method or recursively called 

// postconditions: places non-duplicate data into the node after traverseing the tree

// ---------------------------------------------------------------------------------------------------

bool BinTree::insertStringNode(Node *&treeNode, const string &data) {
    if (treeNode == nullptr) {
        treeNode = new Node{data, nullptr, nullptr};
        return treeNode;
    } 

    if (treeNode->data > data) {
        return insertStringNode(treeNode->left, data);
    } else if (treeNode->data < data) {
        return insertStringNode(treeNode->right, data);
    } else {
        return false;
    }

    return true;
}

// ------------------------------------insertNumNode--------------------------------------------------- 

// insertNumNode: converts string data to double, inserts non-duplicate value into the binary search tree

// preconditions: a valid binary search tree is intialized
//				  method takes const string &data and Node *&treeNode as parameters
//          	  must be called by parent method or recursively called 

// postconditions: converts string data to double 
// 				   and places non-duplicate data into the node after traversing the tree 

// ---------------------------------------------------------------------------------------------------

bool BinTree::insertNumNode(Node *&treeNode, const string &data) {
    if (treeNode == nullptr) {
        treeNode = new Node{data, nullptr, nullptr};
        return true;
    }

    double val = convertString(data);
    double nodeVal = isNum(treeNode->data) ? convertString(treeNode->data) : 0;

    if (nodeVal > val) {
        return insertNumNode(treeNode->left, data);
    } else if (nodeVal < val) {
        return insertNumNode(treeNode->right, data);
    } else {
        return false;
    }

    return true;
}

// ------------------------------------isNum---------------------------------------------------------

// isNum: checks if a string contains a value that can be converted to double

// preconditions: a valid binary search tree is intialized, 
//				  method takes const string &data as a parameter
// 			 	  must be called by parent method

// postconditions: if data contains a value that can be converted to double, returns true  

// ---------------------------------------------------------------------------------------------------

bool BinTree::isNum(const string &data) {
    stringstream ss(data);
    double num;
    return (ss >> num) && ss.eof();
}

// ------------------------------------convertString---------------------------------------------------

// convertString: converts string value to double

// preconditions: a valid binary search tree is intialized 
//				  method takes const string &data as a parameter
//				  must be called by parent method

// postconditions: converts valid string data to a double   

// ---------------------------------------------------------------------------------------------------

double BinTree::convertString(const string &data) {
    return stod(data);
}

// ------------------------------------displayTree----------------------------------------------------

// displayTree: recursively calls printTree to display binary search tree traditionally in prefix

// preconditions: a valid binary search tree is intialized 

// postconditions: tree is displayed in prefix

// ---------------------------------------------------------------------------------------------------

void BinTree::displayTree() const {
    if (isEmpty()) {
        return;
    }
    printTree(root, 1, "Root: ");
}

// ------------------------------------printTree-----------------------------------------------------

// printTree: prints out binary search tree 

// preconditions: takes Node *treeNode, int depth, and const string &prefix as parameters
// 			      a valid binary search tree is intialized 
//			   	  must be called by parent method or recursively called   

// postconditions: tree is displayed in prefix

// ---------------------------------------------------------------------------------------------------

void BinTree::printTree(Node *treeNode, int depth, const string &prefix) const {
    if (treeNode == nullptr) {
        return;
    }

    cout << string(depth * 5, ' ') << prefix << treeNode->data << endl;
    
    if (treeNode->left != nullptr) {
        printTree(treeNode->left, depth + 1, "L---");
    }
    
    if (treeNode->right != nullptr) {
        printTree(treeNode->right, depth + 1, "R---");
    }
}

// ------------------------------------displaySideways----------------------------------------------------

// displaySideways: recursively calls printTree to display binary search tree sideways

// preconditions: a valid binary search tree is intialized 
//			   	  must be called by parent method or recursively called   

// postconditions: tree is displayed in sideways

// -------------------------------------------------------------------------------------------------------

void BinTree::displaySideways() const {
    if(isEmpty()) {
        return;
    } 
    printSidewaysTree(root, 2);
}

// ------------------------------------printSidewaysTree---------------------------------------------------

// printSideTree: prints out binary search tree sideways

// preconditions: takes Node *treeNodea and int depth as parameters
//				  valid binary search tree is intialized 

// postconditions: tree is displayed sideways

// ---------------------------------------------------------------------------------------------------------

void BinTree::printSidewaysTree(Node *treeNode, int depth) const {
    if (treeNode == nullptr) {
        return;
    }

    if (treeNode->right != nullptr) {
        printSidewaysTree(treeNode->right, depth + 1);
    }

    cout << string(depth * 5, ' ')  << treeNode->data << endl;

    if (treeNode->left != nullptr) {
        printSidewaysTree(treeNode->left, depth + 1);
    }
}

// ------------------------------------getHeight--------------------------------------------------- 

// getHeight: recursively calls treeHeight and gets the height of target node in binary search tree

// preconditions: takes const string &data as a parameter
//				  a valid binary search tree is initialized 

// postconditions: returns the height of the target node if it exists in the tree

// -------------------------------------------------------------------------------------------------

int BinTree::getHeight(const string &data) const {
    Node *temp = nullptr;
    retrieve(data, temp);
    return treeHeight(temp);
}

// ------------------------------------treeHeight--------------------------------------------------- 

// treeHeight: gets the height of target node in binary search tree

// preconditions: takes Node *treenode as a parameter
//				  a valid binary search tree is initialized 
//			   	  must be called by parent method or recursively called

// postconditions: returns the height of the target node if it exists in the tree

// -------------------------------------------------------------------------------------------------

int BinTree::treeHeight(Node *treeNode) const { 
   if (treeNode == nullptr) {
        return 0;
   }
   return 1 + max(treeHeight(treeNode->left), treeHeight(treeNode->right));
}

// ------------------------------------osHelper-----------------------------------------------------

// osHelper: performs an in-order traversal and outputs the node data

// preconditions: takes Node *treenode  and ostream &os as parameters
//				  a valid binary search tree is initialized 
//			   	  must be called by parent method or recursively called

// postconditions: outputs the current node's data to ostream in-order

// -------------------------------------------------------------------------------------------------

void BinTree::osHelper(Node *treeNode, ostream &os) const {
    if (treeNode == nullptr) {
        return;
    }
    osHelper(treeNode->left, os);
    os << treeNode->data << " "; 
    osHelper(treeNode->right, os);
}

// ------------------------------------operator<<----------------------------------------------------

// operator<<: recursively calls osHelper to perform an in-order traversal and output the node data

// preconditions: takes const Bintree &tree and ostream &os as parameters
//				  a valid binary search tree is initialized

// postconditions: outputs the current node's data to ostream in-order 

// --------------------------------------------------------------------------------------------------

ostream &operator<<(ostream &os, const BinTree &tree) {
    tree.osHelper(tree.root, os);
    return os << endl;
}

// ------------------------------------operator=----------------------------------------------------

// operator=: constructs a deep copy of the binary search tree

// preconditions: takes rhs as a parameter 
//				  rhs is the tree to be copied
//                assumes copy constructor will run when object is copied 

// postconditions: generates a deep copy of rhs using recursive call to copyNode 
//                 copy tree is generated in the same structure as rhs
// --------------------------------------------------------------------------------------------------

BinTree& BinTree::operator=(const BinTree &rhs) {
    if(!isEmpty()) {
        clear(root);
    }
    copyNode(root, rhs.root);
    return *this;
}

// ------------------------------------operator==----------------------------------------------------

// operator==: recursively calls checkEqual to check if two trees are equal 

// preconditions: takes const BinTree &rhs as a parameter 
//				  valid binary search trees are initialized				  

// postconditions: returns true if trees are equal, false otherwise

// --------------------------------------------------------------------------------------------------

bool BinTree::operator==(const BinTree &rhs) const {
    return checkEqual(root, rhs.root);
}

// ------------------------------------checkEqual----------------------------------------------------

// checkEqual: checks if two trees are equal 

// preconditions: takes Node *treeNode1 and Node treeNode2 as parameters 
//				  valid binary search trees are initialized	

// postconditions: returns true if trees are equal, false otherwise

// --------------------------------------------------------------------------------------------------

bool BinTree::checkEqual(Node *treeNode1, Node *treeNode2) const {
    if (treeNode1 == nullptr && treeNode2 == nullptr) {
        return true;
    }

    if (treeNode1 == nullptr && treeNode2 != nullptr) {
        return false;
    }

    if (treeNode1 != nullptr && treeNode2 == nullptr) {
        return false;
    }

    if (treeNode1->data != treeNode2->data) {
        return false;
    }

    return checkEqual(treeNode1->left, treeNode2->left) &&
        checkEqual(treeNode1->right, treeNode2->right);
}

// ------------------------------------operator!=----------------------------------------------------

// operator!=: checks if two trees are not equal 

// preconditions: takes const BinTree &rhs as a parameter
//				  valid binary search trees are initialized	

// postconditions: returns true if trees are not equal, false otherwise

// --------------------------------------------------------------------------------------------------

bool BinTree::operator!=(const BinTree &rhs) const {
    return !(rhs == *this);
} 

// ------------------------------------bstreeToArray----------------------------------------------------

// bstreeArray: recursively calls treetoArrayHelper to convert binary search tree to a sorted array and clears the tree 

// preconditions: takes string data[] as a parameter
//				  a valid binary search is initialized	

// postconditions: fills an array with node values from the binary search tree

// ----------------------------------------------------------------------------------------------------

void BinTree::bstreeToArray(string data[]) {
    if (isEmpty()) {
        return;
    }

	int size = 0;

	while (size < ARRAYSIZE) {
        data[size] = "";
		size++;
    }

    treeToArrayHelper(root, data, 0);
    clear(root);
}

// ------------------------------------treeToArrayHelper----------------------------------------------------

// treeToArrayHelper: converts binary search tree to a sorted array

// preconditions: takes string data[], Node *treeNode, and int i as parameters
//				  a valid binary search is initialized	
//			   	  must be called by parent method or recursively called

// postconditions: fills an array with node values from the binary search tree after traversing in-order 

// ----------------------------------------------------------------------------------------------------------

int BinTree::treeToArrayHelper(Node *treeNode, string data[], int i) {
    if (treeNode == nullptr) {
        return i;
    }

    i = treeToArrayHelper(treeNode->left, data, i);
    data[i++] = treeNode->data;
    i = treeToArrayHelper(treeNode->right, data, i);

    return i;
 }  

// ------------------------------------arrayToBsTree---------------------------------------------------------

// arrayToBsTree: recursively calls arrayToTreeHelper to convert a sorted array to a balanced binary search tree

// preconditions: takes string data[] as a parameters
//				  a valid binary search tree is initialized	
//			   	  must be called by parent method or recursively called

// postconditions: generates a balanced binary search tree from a sorted array

// ----------------------------------------------------------------------------------------------------------

void BinTree::arrayToBSTree(string data[]) {
    int size = 0;

	if (!isEmpty()) {
		clear(root);
	}

    while (size < ARRAYSIZE && data[size] != "") {
        size++;
    }

    if (size > 0) {
        root = arrayToTreeHelper(data, 0, size - 1);
    }

    for (int i = 0; i < size; ++i) {
        data[i] = "";
    }
}

// ------------------------------------arrayToTreeHelper---------------------------------------------------------

// arrayToBsTree: creates a balanced binary search tree from a sorted array

// preconditions: takes string data[], int start, int end as a parameters
//				  a valid binary search tree is initialized	

// postconditions: generates a balanced binary search tree from a sorted array after traversing in order

// ---------------------------------------------------------------------------------------------------------------

Node *BinTree::arrayToTreeHelper(string data[], int start, int end) {
    if (start > end) {
        return nullptr;
    }
    
    int mid = start + (end - start) / 2;

    Node *midNode = new Node{data[mid], nullptr, nullptr};
    midNode->left = arrayToTreeHelper(data, start, mid-1);
    midNode->right = arrayToTreeHelper(data, mid+1, end);

    return midNode;
} 
