//
// Created by Heather Howe on 10/22/22.
//

#ifndef HW1_STUDENTDQI_H
#define HW1_STUDENTDQI_H

#pragma once
using namespace std;
#include <iostream>
#include "StudentEsa.h"
#include "Student.h"
///HM2
// This is the interface to an "Enhanced" student array that you will write.
//  The methods that need to be supported are shown below. Note: Array auto-resizing may need to be done.

class StudentDQI  {  // Interface
private:   // Uncomment one of the following 2 lines
    StudentEsa* esa;  // Ptr to Orderable Array of Student ptrs
    Student** dqiArry; // Ptr to actual array of Student ptrs. These might be useful;
    int elNum = 0;
    int top; // Index value 1 above highest OA element used
    int btm; // Index value 1 below lowest OA element used
public:
    StudentDQI(int); // Create a DQ with this initial size
    StudentDQI(StudentDQI&); // Equate this to an existing DQ (can use private parts directly)
    ~StudentDQI(); // Destruct the DQI (free OA space)

    int getSize();  // Gets # elements (Student *) in the DQ
    bool isEmpty(); // True if no elements held (“pop” will fail)

    int pushFront(Student*); // Prepend a new element to the front
    Student* popFront();      // Remove the first element and return it
    Student* lookFront();      // Return the first element but do not remove it

    int pushBack(Student*); // Append a new element to the back
    Student* popBack();     // Remove the last element and return it
    Student* lookBack();     // Return the last element but do not remove it
};

#endif //HW1_STUDENTDQI_H
