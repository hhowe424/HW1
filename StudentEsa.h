//
// Created by Heather Howe on 10/4/22.
//

#ifndef HW1_STUDENTESA_H
#define HW1_STUDENTESA_H

#pragma once
using namespace std;
#include <iostream>
#include "Student.h"
///HM1
// This is the interface to an "Enhanced" student array that you will write.
//  The methods that need to be supported are shown below. Note: Array auto-resizing may need to be done.

class StudentEsa
{
private:  // Define what you need
    Student** arry; // Underlying base array which you will allocate
    Student** reallocate;
    int cnum = 0; // Number of students currently in array
    int cmz;
public: // Publically supported methods you need to implement
    StudentEsa(); // Default Constructor
    StudentEsa(StudentEsa&); // Copy Constructor
    StudentEsa(int);  // Initialization Constructor.  Allocate array of this size.  May need to be expanded
    ~StudentEsa(); // Default destructor

    // Return the number of Students in the Collection
    int getNum();

    // GET:  Get and return the ptr to the Student at the specified Index
    // Error if the supplied index >= array size.  Return a NULL ptr
    Student* get(int);

    // SET: Replace
    // Destruct the Student whose ptr is at the supplied index
    // Insert the ptr of the new Student at that index.  Return index # on success
    // Error if the supplied index >= array size.  Return -1
    int set(Student*, int);

    // INSERT
    // Insert the Student ptr at the supplied index, by first "pushing
    // back" every subsequent element, bump Esa Size
    // Note:  This may force a reallocation of the array. Return index # on success
    // Error if the supplied index >= array size.  Return -1
    int insert(Student*, int);

    // REMOVE: Delete
    // Destruct the Student whose ptr is at the supplied index
    // "Pull forward" every subsequent element, decrement Esa Size
    // Error if the supplied index >= array size.  Return -1
    int remove(int);

    // APPEND:
    // Append the pointer of the supplied Student to back of the Esa, bump Esa size
    // Note:  This may force a reallocation of the array. Return index # of new entry on success
    int append(Student*);

    // PREPEND:
    // Prepend the pointer of the supplied Student to the front of the Esa, decrement Esa size
    // Note:  This may force a reallocation of the array.
    // Return index # of new entry on success
    int prepend(Student*);

};


#endif //HW1_STUDENTESA_H
