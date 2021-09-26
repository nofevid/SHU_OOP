//
//  20210926.cpp
//  SHU_OOP
//
//  Created by nofevid on 2021/9/26.
//

#include <iostream>
#include "20210926.h"

using namespace std;

mystring::mystring(const char *mstr){
    mystr = new char[strlen(mstr)+1];
    strcpy(mystr, mstr);
}

mystring::~mystring(){
    if (mystr != NULL){
        delete [] mystr;
    }
}

mystring::mystring(const mystring &ms){
    mystr = new char[strlen(ms.mystr) + 1];
    strcpy(mystr, ms.mystr);
}

unsigned long mystring::mystrlen(const char *mstr){
    return strlen(mstr);
}
