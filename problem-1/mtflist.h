// ------------------------------------------------ mflist.h ----------------------------------------------------------

// Dylan Nelson CSS 343 A

// Creation Date
// 10/1/24

// Date of Last Modification
// 10/5/24

// --------------------------------------------------------------------------------------------------------------------

// File defines the overrided 'contains' method that is to be implemented in mtflist.cpp

// -------------------------------------------------------------------------------------------------------------------- 

// File is expected to inherit functions and variables from CDLinkedList.h
// No special algorithms implemented in this file, file is included in mtflist.cpp 

// --------------------------------------------------------------------------------------------------------------------

#pragma once
#include "CDLinkedList.h"

class MtfList : public CDLinkedList {
public:
    virtual bool contains(int anEntry) override; // overrides 'contains' method in CDLinkedList
};
