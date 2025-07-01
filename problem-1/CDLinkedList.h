// ------------------------------------------------ CDLinkedList.h -----------------------------------------------------

// Dylan Nelson CSS 343 A

// Creation Date
// 9/27/2024

// Date of Last Modification
// 10/5/24

// --------------------------------------------------------------------------------------------------------------------

// This file defines methods and variables to be implemented in CDLinkedList.cpp

// -------------------------------------------------------------------------------------------------------------------- 

// No assumptions or special algorithms implemented in this file, file is included in CDLinkedList.cpp

// --------------------------------------------------------------------------------------------------------------------

#pragma once
#include <iostream>
using namespace std;

struct DListNode { // a list node
    int item;
    DListNode *prev;
    DListNode *next;
};

class CDLinkedList {
public:
    CDLinkedList(); // the constructor
    CDLinkedList(const CDLinkedList &rhs);
    virtual ~CDLinkedList(); // the destructor

    int getCurrentSize() const;
    bool isEmpty() const;


    bool add(int newEntry);
    bool remove(int anEntry);
    void clear();

    // This will search the entry from the list. make sure to use virtual so that transposelist and mtflist can override
    virtual bool contains(int anEntry);

    int getTraverseCount() const;        // return traverseCount
    int retrieve(const int index); // retrieve the data by index. The first item is at index 0.

    void resetTraverseCount() { traverseCount = 0; }

protected:
    DListNode *header;                             // a dummy header
    int sizeCount = 0;
    int traverseCount = 0;
};
