//
//Created by Heather Howe on 10/11/22.
//

#include <iostream>
#include "StudentEsa.h"

using namespace std;

StudentEsa::StudentEsa(){
    arry = nullptr;
    reallocate = nullptr;
    cmz = 0;
}

StudentEsa::StudentEsa(StudentEsa&){
    arry = nullptr;
    reallocate = nullptr;
    cmz = 0;
}

StudentEsa::StudentEsa(int size){
    arry = new Student* [cmz = size]; //change to array of pointers
}

StudentEsa::~StudentEsa(){ }

int StudentEsa::getNum() {
    return cnum;
}

Student* StudentEsa::get(int index){
    if (index >= cmz || index < 0){
        return (NULL);
    }
    return arry[index];
}

int StudentEsa::set(Student* stud, int index){
    if(index > cmz){
        return -1;
    }
    arry[index] = stud;
}

int StudentEsa::insert(Student* stud, int index){
    if(index > cmz){
        return -1;
    }
    else if(cnum >= cmz){
        reallocate = new Student* [cmz + cmz];
        for(int i = 0; i < cmz; i++){
            reallocate[i] = arry[i];
        }
        arry = reallocate;
        cmz = cmz + cmz;
    }
    for(int i = cnum; i > index; i--){
        arry[i] = arry[i - 1];
    }
    arry[index] = stud;
    cnum++;

    return index;
}

int StudentEsa::remove(int index){
    if(index >= cmz || index < 0){
        return -1;
    }
    for(int i = index; i < (cnum - 1); i++){
        arry[i] = arry[i + 1];
    }
    cnum--;
}

int StudentEsa::append(Student* stud){
    static int index = 0;
    if(cnum >= cmz){
        reallocate = new Student* [cmz + cmz];
        for(int i = 0; i < cmz; i++){
            reallocate[i] = arry[i];
        }
        arry = reallocate;
        cmz = cmz + cmz;
    }
    arry[cnum] = stud;
    index = cnum++;

    return index;
}

int StudentEsa::prepend(Student* stud){
    if(cnum >= cmz){
        reallocate = new Student* [cmz + cmz];
        for(int i = 0; i < cmz; i++){
            reallocate[i] = arry[i];
        }
        arry = reallocate;
        cmz = cmz + cmz;
    }
    for(int i = cnum; i > 0; i--){
        arry[i] = arry[i - 1];
    }
    arry[0] = stud;
    int index = 0;
    cnum++;

    return index;
}


