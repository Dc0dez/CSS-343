// ------------------------------------------------ mtfdriver.cpp -----------------------------------------------------

// Programmer Name Course Section Number
// Dylan Nelson CSS 343 A

// Creation Date
// 10/5/24

// Date of Last Modification
// 10/5/24

// --------------------------------------------------------------------------------------------------------------------

// File is used to test the functionality of all the methods in mtflist.cpp

// -------------------------------------------------------------------------------------------------------------------- 

// Tests will correctly output expected values if the methods in CDLinkedList.cpp are structured correctly
// Tests check for proper addition, removal, and retrieval of nodes; list traversals; and if the list nodes contain specific values for the original list and the copied list
// Tests will ensure that nodes containing specific values are correctly moved to the front of the list
// Tests will clear all the values from the lists at the end and ensure double clearing does not break the program

// --------------------------------------------------------------------------------------------------------------------

#include "mtflist.h" 
#include <iostream>
#include <string>

using namespace std;

int main() {
    MtfList testList;
    
    // reset all traverse count first
    testList.resetTraverseCount();
    cout << "Make a list" << endl;

    testList.add(1);
    testList.add(7);
    testList.add(8);
    testList.add(5);
    testList.add(1);

    cout << "Reset traverse count: traverseCount=" << testList.getTraverseCount() << endl;

    // tests if list has correct values
    cout << "# members in original list 1->7->8->5->1: size=" << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++)
        cout << testList.retrieve(i) << endl;
    
    cout << endl;
    testList.remove(8);

    // tests 'remove' method
    cout << "# members in original list after remove 8: size= " << testList.getCurrentSize() << ", traverseCount="<<testList.getTraverseCount() << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++)
        cout << testList.retrieve(i) << endl;
    
    cout << endl; 
    cout<< "testList.contains(8)="<<testList.contains(8)<<endl;

    // tests 'contains' method
    cout << "# members in original list after access 8: size= " << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++)
        cout << testList.retrieve(i) << endl;

    cout << endl;
    cout<< "testList.contains(7)="<<testList.contains(7)<<endl;

    cout << "# members in original list after access 7: size= " << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++)
        cout << testList.retrieve(i) << endl;

    cout << endl;
    testList.add(6);

    // tests pointers after removing a value and adding to the list
    cout << "# members in original list after adding 6: size=" << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++)
        cout << testList.retrieve(i) << endl;

    cout << endl; 
    testList.remove(1);
    testList.remove(7);
    testList.remove(5);
    testList.remove(6); 
    cout << "testList.contains(1)=" << testList.contains(1) << endl;
    cout << "testList.contains(7)=" << testList.contains(7) << endl;
    cout << "testList.contains(5)=" << testList.contains(5) << endl;
    cout << "testList.contains(6)=" << testList.contains(6) << endl;

    // tests pointers after using remove to clear the list
    cout << "# members in original list after removing all elements: size=" << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = 0; i <= testList.getCurrentSize(); i++){
        if (testList.isEmpty()) {
        cout << "List is empty" <<endl;
        }
        cout << testList.retrieve(i) << endl;
    }

    cout << endl;
    testList.add(1);
    testList.add(9);
    testList.add(2);
    testList.add(4);
    testList.add(3);

    // tests adding to the list after removing all values
    cout << "# members in original list 1->9->2->4->3: size=" << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++)
        cout << testList.retrieve(i) << endl;
    
    cout<< endl;

    // tests reversing the list
    cout << "# members in reversed original list 3->4->2->9->1: size=" << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = testList.getCurrentSize()-1; i >= 0; i--)
        cout << testList.retrieve(i) <<endl;
    
    MtfList copiedList = testList;
  
    cout<< endl;
    testList.remove(3);

    // tests removing the front of the list
    cout << "# members in original list after removing 3: size=" << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++)
        cout << testList.retrieve(i) << endl;

    cout<< endl;
    testList.remove(1);

    // tests removing the back of the list
    cout << "# members in original list after removing 1: size=" << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++)
        cout << testList.retrieve(i) << endl;

    cout<< endl;

    // tests copy constructor
    cout << "# members in copied list 1->9->2->4->3: size=" << copiedList.getCurrentSize() << ", traverseCount=" << copiedList.getTraverseCount() << endl;
    for (int i = 0; i < copiedList.getCurrentSize(); i++)
        cout << copiedList.retrieve(i) << endl;

    cout<< endl;
    copiedList.add(6);

    // tests adding to the copied list
    cout << "# members in copied list after adding 6: size=" << copiedList.getCurrentSize() << ", traverseCount=" << copiedList.getTraverseCount() << endl;
    for (int i = 0; i < copiedList.getCurrentSize(); i++)
        cout << copiedList.retrieve(i) << endl;
        
    cout<< endl;
    copiedList.remove(6);

    // tests remove from the front of the copied list
    cout << "# members in copied list after removing 6: size=" << copiedList.getCurrentSize() << ", traverseCount=" << copiedList.getTraverseCount() << endl;
    for (int i = 0; i < copiedList.getCurrentSize(); i++)
        cout << copiedList.retrieve(i) << endl;

    cout<< endl;
    cout<< "copiedList.contains(6)="<<copiedList.contains(6)<<endl;

    // tests contains method for copied list
    cout << "# members in copied list after access 6: size= " << copiedList.getCurrentSize() << ", traverseCount=" << copiedList.getTraverseCount() << endl;
    for (int i = 0; i < copiedList.getCurrentSize(); i++)
        cout << copiedList.retrieve(i) << endl;

        
    cout<< endl;
    copiedList.add(0);

    // tests adding 0 to the copied list
    cout << "# members in copied list after adding 0: size=" << copiedList.getCurrentSize() << ", traverseCount=" << copiedList.getTraverseCount() << endl;
    for (int i = 0; i < copiedList.getCurrentSize(); i++)
        cout << copiedList.retrieve(i) << endl;

    cout<< endl;
    copiedList.remove(1);

    // tests remove from back of the copied list
    cout << "# members in copied list after removing 1: size=" << copiedList.getCurrentSize() << ", traverseCount=" << copiedList.getTraverseCount() << endl;
    for (int i = 0; i < copiedList.getCurrentSize(); i++)
        cout << copiedList.retrieve(i) << endl;

    cout << endl;
    cout<< "copiedList.contains(0)="<<copiedList.contains(0)<<endl;

    // tests 'contains' method for copied list
    cout << "# members in copied list after access 0: size= " << copiedList.getCurrentSize() << ", traverseCount=" << copiedList.getTraverseCount() << endl;
    for (int i = 0; i < copiedList.getCurrentSize(); i++)
        cout << copiedList.retrieve(i) << endl;

    cout << endl;
    cout<< "copiedList.contains(2)="<<copiedList.contains(2)<<endl;

    cout << "# members in copied list after access 2: size= " << copiedList.getCurrentSize() << ", traverseCount=" << copiedList.getTraverseCount() << endl;
    for (int i = 0; i < copiedList.getCurrentSize(); i++)
        cout << copiedList.retrieve(i) << endl;

    cout<< endl;
    copiedList.clear();

    // tests 'clear' method for copied list
    cout << "# members in copied list after clearing all elements: size=" << copiedList.getCurrentSize() << ", traverseCount=" << copiedList.getTraverseCount() << endl;
    for (int i = 0; i <= copiedList.getCurrentSize(); i++){
        if (copiedList.isEmpty()) {
        cout << "List is empty" <<endl;
        }
        cout << copiedList.retrieve(i) << endl;
    }

    cout<< endl;

    // prints out original list, showing copied list is a deep copy
    cout << "# members in original list: size=" << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++)
        cout << testList.retrieve(i) << endl;

    cout<< endl;
    testList.clear();

    // tests clear on original list
    cout << "# members in original list after clearing all elements: size=" << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = 0; i <= testList.getCurrentSize(); i++){
        if (testList.isEmpty()) {
        cout << "List is empty" <<endl;
        }
        cout << testList.retrieve(i) << endl;
    }
        
    cout<< endl;
    testList.clear();

    // tests for double clear
    cout << "Check for double clear: size=" << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = 0; i <= testList.getCurrentSize(); i++){
        if (testList.isEmpty()) {
        cout << "List is empty" <<endl;
        }
        cout << testList.retrieve(i) << endl;
    }

    cout<< endl;
    testList.remove(1);

    //tests for remove after list is empty

    cout << "Check for remove after list is empty: size=" << testList.getCurrentSize() << ", traverseCount=" << testList.getTraverseCount() << endl;
    for (int i = 0; i <= testList.getCurrentSize(); i++){
        if (testList.isEmpty()) {
        cout << "List is empty" <<endl;
        }
        cout << testList.retrieve(i) << endl;
    }
    
    return 0;
}
