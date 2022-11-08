//
// Created by Heather Howe on 10/22/22.
//

#include <iostream>
#include "StudentDQI.h"

using namespace std;

// Copy Constructor
StudentDQI::StudentDQI(StudentDQI&){}

// Initialization Constructor
StudentDQI::StudentDQI(int size){
    esa = new StudentEsa(size);
    top = size / 2;
    btm = top + 1;
    for(int i = 0; i < top; i++){
        esa->append(nullptr);
    }
}

// Destructor
StudentDQI::~StudentDQI(){
    delete[] esa;
}

// Return number of elements/students in queue
int StudentDQI::getSize() {
    return elNum;
}

// True if no elements held (“pop” will fail)
bool StudentDQI::isEmpty(){
    if(elNum == 0){ return true; }
    else{ return false; }
}

// Prepend a new element to the front
int StudentDQI::pushFront(Student* stud){
    esa->insert(stud, top);
    top--;
    elNum++;
}

// Remove the first element and return it
Student* StudentDQI::popFront(){
    Student* popF = esa->get(top + 1);
    esa->set(nullptr, top + 1);
    top++;
    elNum--;
    return popF;
}

// Return the first element but do not remove it
Student* StudentDQI::lookFront(){
    return esa->get(top + 1);
}

// Append a new element to the back
int StudentDQI::pushBack(Student* stud){
    esa->append(stud);
    btm++;
    elNum++;
}

// Remove the last element and return it
Student* StudentDQI::popBack(){
    Student* popB = esa->get(btm - 1);
    esa->set(nullptr, btm - 1);
    btm--;
    return popB;
}

// Return the last element but do not remove it
Student* StudentDQI::lookBack(){
    return esa->get(btm - 1);
}





