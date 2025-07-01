// ------------------------------------------------ mtflist.cpp -------------------------------------------------------

// Dylan Nelson CSS 343 A

// Creation Date
// 10/1/24

// Date of Last Modification
// 10/5/24

// --------------------------------------------------------------------------------------------------------------------

// File implements overrided 'contains' method

// -------------------------------------------------------------------------------------------------------------------- 

// File inherits all functionality of CDLinkedList.cpp
// MtfList::contains will override CDLinkedList.cpp and perform the action of placing the accessed node at the front of the list
// Makes use of the dummy node to initialize the list and simplify method implementation

// --------------------------------------------------------------------------------------------------------------------

#include "mtflist.h"

// ------------------------------------contains------------------------------------------------

// contains: places accessed node at the front of the list

// preconditions: a valid list is initialized, method takes anEntry as a parameter, 
//                and parameter is a valid integer

// postconditions: if 'anEntry' is found, places the accessed node at the front of the list,
//                 the list structure is updated accordingly, and 'traverseCount' is incremented for each node checked

// -------------------------------------------------------------------------------------------- 

bool MtfList::contains(int anEntry) {
    DListNode *curr = header->next; // initializes pointer 'curr' to the next node in the list
    while (curr != header) { // loops through the list while 'curr' is not equal to header
        if (curr->item == anEntry) { // checks if current node contains 'anEntry', places current node at the front of the list if found, updates pointers, and returns true
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev; 
            curr->next = header->next;
            curr->prev = header;
            header->next->prev = curr;
            header->next = curr; 
            return true;
        }
        curr = curr->next; // updates 'curr' to next node if current value does not equal 'anEntry'
        traverseCount++;
    } 
    return false; // returns false if 'anEntry' is not found
}
