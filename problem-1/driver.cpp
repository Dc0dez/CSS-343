// ------------------------------------------------ driver.cpp -------------------------------------------------------

// Taggart Vowels: CSS343 Section A

// 27 September 2024

// 5 October 2024

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this program is to thoroughly test CDLinkedList and its child classes MTFList and TransposeList.

// -------------------------------------------------------------------------------------------------------------------- 

// By using assert and printing outputs, user can see if the classes are functioning correctly.
// Every method in the classes is tested for edge cases and memory leaks.

// --------------------------------------------------------------------------------------------------------------------

#include "mtflist.h"
#include "transposelist.h"
#include "CDLinkedList.h"
#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

// ------------------------------------printList----------------------------------------------- 

// Description

// printList(List testList, bool forward = true): prints the list.
// preconditions: this contains a header node and potentially other nodes with valid data.
//				  list has to be type CDLinkedList, MtfList, or TransposeList.
//				  param testList is the list to be printed.
//				  param forward determines the direction to print.
// postconditions: list is printed to terminal.
//                 will not modify the list at all.

// -------------------------------------------------------------------------------------------- 
template<typename List>
void printList(List testList, bool forward = true)
{
	if (forward)
	{
		for (int i = 0; i < testList.getCurrentSize(); i++)
		cout << testList.retrieve(i);
	} else {
		for (int i = testList.getCurrentSize()-1; i >= 0; i--)
		cout << testList.retrieve(i);
	}
	cout << endl;
}

// ------------------------------------baseTests----------------------------------------------- 

// Description

// baseTests(List testList): runs base tests provided by assignment.
// preconditions: this contains a header node and potentially other nodes with valid data.
//				  list has to be type CDLinkedList, MtfList, or TransposeList.
//			 	  assumes list has 5,8,7,1 in it. order of list depends
//				  param testList is the list to be tested.
// postconditions: tests basic functions

// -------------------------------------------------------------------------------------------- 
template<typename List>
void baseTests(List testList)
{
	cout<<"Reset traverse count: traverseCount="<<testList.getTraverseCount()<<endl;

	cout << "#members 1->7->8->5->1: size=" << testList.getCurrentSize() << ", traverseCount="<<testList.getTraverseCount()<<endl;;
	cout<<"traverse count="<<testList.getTraverseCount()<<endl;
	for (int i = 0; i < testList.getCurrentSize(); i++)
		cout << testList.retrieve(i) << endl;

	cout << endl;
	testList.remove(8);

	cout << "#After remove 8, : size= " << testList.getCurrentSize() << ", traverseCount="<<testList.getTraverseCount()<<endl;;
	cout<<"traverse count="<<testList.getTraverseCount()<<endl;
	for (int i = 0; i < testList.getCurrentSize(); i++)
		cout << testList.retrieve(i) << endl;

	cout << endl;
	cout<<"testList.contains(8)="<<testList.contains(8)<<endl;

	cout << "# members, after access 8: size= " << testList.getCurrentSize() << ", traverseCount="<<testList.getTraverseCount()<<endl;;
	for (int i = 0; i < testList.getCurrentSize(); i++)
		cout << testList.retrieve(i) << endl;

	cout<<"testList.contains(7)="<<testList.contains(7)<<endl;

	cout << "# members, after access 7: size= " << testList.getCurrentSize() << ", traverseCount="<<testList.getTraverseCount()<<endl;
	for (int i = 0; i < testList.getCurrentSize(); i++)
		cout << testList.retrieve(i) << endl;
	cout << endl;
}

// ------------------------------------test1----------------------------------------------- 

// Description

// test1(List testList): tests copy constructor and functions on copied list
// preconditions: this contains a header node and potentially other nodes with valid data.
//				  list has to be type CDLinkedList, MtfList, or TransposeList.
//				  param testList is the list to be tested.
// postconditions: prints list, copied list, and that the addresses are different

// -------------------------------------------------------------------------------------------- 
template<typename List>
void test1(List testList)
{
	// Copy Constructor
	List testList2 = testList;
	printList(testList);
	printList(testList2);
	assert(testList.getCurrentSize() == testList2.getCurrentSize());
	assert(&testList != &testList2);
	cout << "size is the same and addresses are different" << endl;
	
	// Removes head
	assert(testList2.remove(testList.retrieve(0)));

	// Clears copied list
	testList2.clear();
	assert(testList2.isEmpty());

	// Tests contains on only node
	testList2.add(1);
	assert(testList2.contains(1) == true);
	assert(testList2.retrieve(0) == 1);

	// Remove only node in list
	testList2.remove(1);
	assert(testList2.contains(1) == false);
	assert(testList2.retrieve(0) == -1);
}

// ------------------------------------test2----------------------------------------------- 

// Description

// test2(List testList): tests repeated use of add and contains
// preconditions: this contains a header node and potentially other nodes with valid data.
//				  list has to be type CDLinkedList, MtfList, or TransposeList.
// postconditions: lists should be printed in reverse

// -------------------------------------------------------------------------------------------- 
void test2()
{
	MtfList mtfList;
	TransposeList tpList;

	for (int i = 1; i <= 5; i++) 
	{
		mtfList.add(i);
		tpList.add(i);
	}

	// Reverse list with child classes
	cout << "Should reverse the list using MTFList" << endl;
	cout << "Original list = "; printList(mtfList);

	for (int i = 5; i > 0; i--) assert(mtfList.contains(i));
	cout << "MTFList after = "; printList(mtfList);

	cout << "Should reverse the list using TransposeList" << endl;
	for (int i = 5; i > 0; i--)
		for (int j = 5; j >= i; j--)
			assert(tpList.contains(i));
	cout << "TransverseList after = "; printList(tpList);
	cout << endl;
}

// ------------------------------------test1----------------------------------------------- 

// Description

// test1(List testList): tests forceful/repeated use of add, remove, and clear.
// preconditions: this contains a header node and potentially other nodes with valid data.
//				  list has to be type CDLinkedList, MtfList, or TransposeList.
//				  param testList is the list to be tested.
// postconditions: prints a message if successful.

// -------------------------------------------------------------------------------------------- 
template<typename List>
void test3(List testList)
{
	testList.clear(); // Needs a clear list to function
	testList.add(1);
	for (int i = 1; i <= 5; i++) assert(testList.add(1) == false);
	for (int i = 2; i <= 100; i++) assert(testList.add(i) == true);

	for (int i = 0; i < 100; i++) assert(testList.retrieve(i) == 100-i);

	assert(testList.isEmpty() == false);
    assert(testList.getCurrentSize() == 100);
	
	testList.remove(1);
	for (int i = 1; i <= 5; i++) assert(testList.remove(1) == false);
	for (int i = 2; i <= 100; i++) assert(testList.remove(i) == true);

	// Test Clear
	testList.clear();
	assert(testList.isEmpty() == true);
    assert(testList.getCurrentSize() == 0);

	cout << "Test 3 passed" << endl;
}

// ------------------------------------test1----------------------------------------------- 

// Description

// test1(List testList): tests if the next and prev pointers are connected properly.
// preconditions: this contains a header node and potentially other nodes with valid data.
//				  list has to be type CDLinkedList, MtfList, or TransposeList.
//				  param testList is the list to be tested.
// postconditions: prints lists both ways.
// 				   have to manually verify the accuracy of prints.

// -------------------------------------------------------------------------------------------- 
template<typename List>
void test4(List testList)
{
	cout << "Forward List:  ";
	printList(testList);

	cout << "Backward List: ";
	printList(testList, false);
}

int main() 
{
	CDLinkedList testList1;
	MtfList testList2;
	TransposeList testList3;
	
	// Reset all traverse count first
	testList1.resetTraverseCount();
	testList2.resetTraverseCount();
	testList3.resetTraverseCount();
	cout << "Make a list" << endl;

	// Test cases
	vector<vector<int>> nums {
		{1,7,8,5,1},
		{1,3,5,7,9},
		{5,4,3,2,1},
		{9,8,4,6,4}
	};

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums[i].size(); j++)
		{
			testList1.add(nums[i][j]);
			testList2.add(nums[i][j]);
			testList3.add(nums[i][j]);
		}

		if (i == 0)
		{ // Only run the base tests once
			cout << "\nCDLinkedList" << endl;
			baseTests(testList1);
			cout << "\nMTFList" << endl;
			baseTests(testList2);
			cout << "\nTransposeList" << endl;
			baseTests(testList3);
		}
		
		cout << "\nCDLinkedList" << endl;
		test1(testList1);
		cout << "\nMTFList" << endl;
		test1(testList2);
		cout << "\nTransposeList" << endl;
		test1(testList3);

		cout << endl;
		test3(testList1);
		test3(testList2);
		test3(testList3);
		
		cout << "\nCDLinkedList" << endl;
		test4(testList1);
		cout << "\nMTFList" << endl;
		test4(testList2);
		cout << "\nTransposeList" << endl;
		test4(testList3);

		//Clear
		testList1.clear();
		testList2.clear();
		testList3.clear();
	}
	cout << endl;
	test2();
	return 0;
}