// ------------------------------------------------ transposelist.cpp -------------------------------------------------------

// Programmer Name Course Section Number
// Dylan Nelson CSS 343 A

// Creation Date
// 10/01/24

// Date of Last Modification
// 10/5/24

// --------------------------------------------------------------------------------------------------------------------------

// File implements overrided 'contains' method

// -------------------------------------------------------------------------------------------------------------------------- 

// File inherits all functionality of CDLinkedList.cpp
// TransposeList::contains will override CDLinkedList.cpp and perform the action of swapping the accessed node with the previous node
// Makes use of the dummy node to initialize the list and simplify method implementation

// --------------------------------------------------------------------------------------------------------------------------

#include "transposelist.h"

// ------------------------------------contains------------------------------------------------- 

// contains: swaps the accessed node with the previous node in the list

// preconditions: a valid list is initialized, method takes int anEntry as a formal parameter, 
//                and parameter is a valid integer

// postconditions: if anEntry is found, swaps the accessed node with the previous node, 
//                 the list structure is updated accordingly, and 'traverseCount' is incremented for each node checked

// --------------------------------------------------------------------------------------------- 

bool TransposeList::contains(int anEntry) {
    DListNode *curr = header->next; // initialize pointer 'curr' to the next node in the list
    while (curr != header) { // loops through the list while 'curr' is not equal to header
        if (curr->item == anEntry) { // checks if current node contains 'anEntry', swaps current node with the previous node if found, updates pointers, and returns true
            DListNode *prevNode = curr->prev;
            prevNode->next = curr->next; 
            curr->next->prev = prevNode;
            curr->next = prevNode;
            curr->prev = prevNode->prev; 
            prevNode->prev->next = curr;
            prevNode->prev = curr; 
            return true; 
        }
        curr = curr->next; // updates 'curr' to next node if current value does not equal 'anEntry'
        traverseCount++; 
    } 
    return false; // returns false if 'anEntry' is not found
}
