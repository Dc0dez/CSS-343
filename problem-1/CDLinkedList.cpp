// ------------------------------------------------ CDLinkedList.cpp ---------------------------------------------------

// Dylan Nelson CSS 343 A

// Creation Date
// 9/27/24

// Date of Last Modification
// 10/5/24

// ---------------------------------------------------------------------------------------------------------------------

// File implements declared methods in CDLinkedList.h 

// --------------------------------------------------------------------------------------------------------------------- 

// File is expected to implement methods and functions from CDLinkedList.h
// Makes use of the dummy node to initialize the list and simplify method implementation
// No special algorithms used

// ---------------------------------------------------------------------------------------------------------------------

#include "CDLinkedList.h"

// ------------------------------------CDLinkedList----------------------------------------------- 

// CDLinkedList: constructs linkedlist with dummy header node

// preconditions: assumes constructor will run when object is initialized 

// postconditions: if object is initialized, creates an empty list with the dummy header

// -----------------------------------------------------------------------------------------------

CDLinkedList::CDLinkedList() {
    header = new DListNode{0, nullptr, nullptr};
    header->next = header->prev = header; // sets 'header' next and previous pointers to point at 'header'
}

// ------------------------------------CDLinkedList----------------------------------------------- 

// CDLinkedList: constructs a deep copy of CDLinkedList

// preconditions: takes CD LinkedList &rhs as a formal parameter, rhs is the list to be copied
//                assumes copy constructor will run when object is copied 

// postconditions: generates a deep copy of CDLinkedList, list is generated in the same order as rhs, and copied list sizecount is updated

// -----------------------------------------------------------------------------------------------

CDLinkedList::CDLinkedList(const CDLinkedList &rhs) {
    DListNode *rhsCurr = rhs.header;
    DListNode *newNode = new DListNode();
    newNode->item = rhsCurr->item; 
    header = newNode;
    DListNode *prevNode = header;
    rhsCurr = rhsCurr->next;

    while (rhsCurr != rhs.header) {
        newNode = new DListNode();
        newNode->item = rhsCurr->item;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        prevNode = newNode;
        rhsCurr = rhsCurr->next;
        sizeCount++;
    }

    prevNode->next = header;
    header->prev = prevNode;
}

// ------------------------------------~CDLinkedList----------------------------------------------- 

// ~CDLinkedList: deletes header node and deallocates memory 

// preconditions: a valid list is initialized   

// postconditions: all dynamically allocated memory for the list nodes, including the dummy, is deallocated

// ------------------------------------------------------------------------------------------------

CDLinkedList::~CDLinkedList() {
    clear();
    delete header;
    header = nullptr;
}

// ------------------------------------getCurrentSize----------------------------------------------- 

// getCurrentSize: gets the current number of elements in the list

// preconditions: a valid list is initialized   

// postconditions: returns the size of the list, excluding the dummy header

// -------------------------------------------------------------------------------------------------

int CDLinkedList::getCurrentSize() const {
    return sizeCount;
}

// ------------------------------------isEmpty----------------------------------------------- 

// isEmpty: checks if the list is empty

// preconditions: a valid list is initialized  

// postconditions: returns true if the list contains no elements

// ------------------------------------------------------------------------------------------
    
bool CDLinkedList::isEmpty() const {
    return sizeCount <= 0; 
}

// ------------------------------------add--------------------------------------------------- 

// add: adds nodes containing non-duplicate elements to the list

// preconditions: a valid list is intialized, method takes newEntry as a parameter,
//                and 'newEntry' is a valid non-duplicate integer   

// postconditions: if 'newEntry' is not currently in the list, 'add' appends a new node containing 
//                 the value to the front of the list, and 'traversecount' and 'sizecount' are updated

// ------------------------------------------------------------------------------------------

bool CDLinkedList::add(int newEntry) {
    if (!contains(newEntry)) {
        DListNode *newNode = new DListNode();
        newNode->item = newEntry;
        newNode->next = header->next;
        newNode->prev = header;
        header->next->prev = newNode;
        header->next = newNode;
        sizeCount++;
        return true;
    }
    return false;
}

// ------------------------------------remove--------------------------------------------------- 

// remove: removes specified nodes from the list if list is not empty

// preconditions: a valid list is intialized, method takes int newEntry as a parameter,
//                and 'newEntry' is a valid integer in the list 

// postconditions: if 'newEntry' is currently in the list, the node containing the value is deleted from the list, 
//                 and 'traversecount' and 'sizecount' are updated

//                 if remove is used to empty the list, previous and next pointers are set to point to header

// ---------------------------------------------------------------------------------------------

bool CDLinkedList::remove(int anEntry) {
    if (!isEmpty()) {
        DListNode *curr = header->next; 
        while (curr != header) {
            if (curr->item == anEntry) {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev; 
                delete curr; 
                sizeCount--; 
                return true;
            } 
            if (header->next == header) {
                header->next = header->prev = header;
                return true;
            }
            curr = curr->next;
            traverseCount++;
        } 
    } 
    return false;
}
    
// ------------------------------------clear--------------------------------------------------- 

// clear: removes all nodes from the list if it list not empty

// preconditions: a list containing nodes currently exists

// postconditions: if list contains nodes with elements, all nodes in the list are deleted, 
//                 ,'sizecount' is updated, and previous and next pointers are set to point to head

// --------------------------------------------------------------------------------------------

void CDLinkedList::clear() {
    if (!isEmpty()) {
        DListNode *curr = header->next;
        DListNode *nextNode = nullptr;
        while (curr != header) {
            nextNode = curr->next;
            delete curr;
            curr = nextNode;
            sizeCount--;
        }
        header->next = header->prev = header;
    }
}

// ------------------------------------contains------------------------------------------------

// contains: checks if an element is currently in the list

// preconditions: a valid list is intialized, method takes 'int anEntry' as a formal parameter, 
//                parameter is a valid integer

// postconditions: if 'anEntry' equals the current value in the list, 
//                 returns true, and 'traverseCount' is incremented for each node checked

// -------------------------------------------------------------------------------------------- 

bool CDLinkedList::contains(int anEntry) {
    DListNode *curr = header->next;
    while (curr != header) {
        if (curr->item == anEntry) {
            return true;
        }
        curr = curr->next;
        traverseCount++; 
    } 
    return false;
}

// ------------------------------------getTraverseCount------------------------------------------------

// getTraverseCount: gets the amount of list traversals

// preconditions: a valid list is intialized

// postconditions: returns the number of traversals performed 

// ----------------------------------------------------------------------------------------------------

int CDLinkedList::getTraverseCount() const {
    return traverseCount;
}        

// ------------------------------------retrieve--------------------------------------------------- 

// retrieve: retrieves the element at a specified index in the list

// preconditions: a valid list is intialized, method takes 'const int index' as a parameter,
//                and 'index' is a valid integer in the list 

// postconditions: if the node at 'index' exists, the corresponding element is returned, 
//                 and 'traversecount' is incremented for each node checked

//                 if 'index' is out of range, returns -1

// ---------------------------------------------------------------------------------------------

int CDLinkedList::retrieve(const int index ) {
    DListNode *curr = header->next;
    int count = 0; 
    while (curr != header) {
        if (count == index) {
            return curr->item;
        }
        curr = curr->next;
        count++;
        traverseCount++;
    }
    return -1;
}

