//
//  20210926.cpp
//  SHU_OOP
//
//  Created by nofevid on 2021/9/26.
//

#include <iostream>
#include <cstring>
#include <string.h>
#include "mystring.h"

using namespace std;

//构造函数实现
mystring::mystring(const char *mstr){
    mydata = new char[mystrlen(mstr)+1];
    mystrcpy(mydata, mstr);
    mylen = mystrlen(mydata);
    //cout << "Constructing an object of mystring " << mstr << "." << endl;
}

mystring::mystring (const mystring& mstr, size_t pos, size_t len){
    char temp[len];
    if ((pos+len-1)<mstr.mylen){
        for(int i = 0; i < len; i++){
            temp[i] = mstr.mydata[pos+i];
        }
        mylen = len;
    }else{
        mylen = mstr.mylen - pos;
        for(int i = 0; i < mylen; i++){
            temp[i] = mstr.mydata[pos+i];
        }
    }
    mydata = new char[mylen+1];
    for(int i = 0; i < mylen; i++){
        mydata[i] = temp[i];
    }
}

mystring::mystring(const mystring& mstr, size_t n){
    mydata = new char[n+1];
    mylen = n;
    for(int i = 0; i < mylen; i++){
        mydata[i] = mstr.mydata[i];
    }
}

mystring::mystring (size_t n, char c){
    
}

//析构函数实现
mystring::~mystring(){
    if (mydata != NULL){
        //cout << "Destroying an object of mystring " << mydata << "." << endl;
        delete [] mydata;
        mylen = 0;
    }
}

mystring::mystring(const mystring &ms){
    mydata = new char[strlen(ms.mydata) + 1];
    strcpy(mydata, ms.mydata);
}


//mystrlen实现，有问题，待修
unsigned long mystring::mystrlen(const char *mstr) const{
    return strlen(mstr);
}

unsigned long mystring::mystrlen(const mystring &mstr) const{
    return strlen(mstr.mydata);
}

unsigned long mystring::mystrlen(){
    return(this->mylen);
}

//show实现，重载输出运算符后可不用
void mystring::mystr_show() const{
    cout << "\"" << mydata << "\"" << endl;
}

//upperstr实现，待修
void mystring::upperstr(){
    cout << "Upper \"" << mydata << "\" -> \"";
    //strupr(mystr);
    cout << mydata << "\"." << endl;
}

//mystrcpy实现，待修
char *mystring::mystrcpy(char *mstr_des, const char *mstr_ori){
    return(strcpy(mstr_des, mstr_ori));
}

char *mystring::mystrcpy(mystring mstr_des, mystring mstr_ori){
    return(strcpy(mstr_des.mydata, mstr_ori.mydata));
}
