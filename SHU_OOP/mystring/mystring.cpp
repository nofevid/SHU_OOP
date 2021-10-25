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
mystring::mystring(const char* mstr){
    mydata = new char[mystrlen(mstr)+1];
    strcpy(mydata, mstr);
    mylen = mystrlen(mydata);
    mydata[mylen]='\0';
    //cout << "Constructing an object of mystring " << mstr << "." << endl;
}

//mystring::mystring (const mystring& mstr, size_t pos, size_t len){
//    char temp[len];
//    if ((pos+len-1)<mstr.mylen){
//        for(size_t i = 0; i < len; i++){
//            temp[i] = mstr.mydata[pos+i];
//        }
//        mylen = len;
//    }else{
//        mylen = mstr.mylen - pos;
//        for(size_t i = 0; i < mylen; i++){
//            temp[i] = mstr.mydata[pos+i];
//        }
//    }
//    mydata = new char[mylen+1];
//    for(size_t i = 0; i < mylen; i++){
//        mydata[i] = temp[i];
//    }
////    mydata = mydata + temp;
//}

mystring::mystring (const mystring& mstr, size_t pos, size_t len){
    if ((pos+len-1)<mstr.mylen){
        mylen = len;
    }else{
        mylen = mstr.mylen - pos;
    }
    mydata = new char[mylen+1];
    for(size_t i = 0; i < mylen; i++){
        mydata[i] = mstr.mydata[pos+i];
    }
    mydata[mylen]='\0';
}

mystring::mystring(const mystring& mstr, size_t n){
    mydata = new char[n+1];
    mylen = n;
    for(size_t i = 0; i < mylen; i++){
        mydata[i] = mstr.mydata[i];
    }
    mydata[mylen]='\0';
}

mystring::mystring (size_t n, char c){
    mylen = n;
    mydata = new char[n+1];
    for(size_t i = 0; i < mylen; i++){
        mydata[i] = c;
    }
    mydata[mylen]='\0';
}

//析构函数实现
mystring::~mystring(){
    if (mydata != NULL){
        //cout << "Destroying an object of mystring " << mydata << "." << endl;
        delete [] mydata;
        mylen = 0;
    }
}

mystring::mystring(const mystring& ms){
    mydata = new char[strlen(ms.mydata) + 1];
    strcpy(mydata, ms.mydata);
}

//重载'='实现
mystring& mystring::operator=(const mystring& mstr){
    if(&mstr != this){
        delete [] mydata;
        mydata = new char[mstr.mylen + 1];
        strcpy(mydata, mstr.mydata);
        mylen = mstr.mylen;
    }
    return *this;
}

//重载'+'实现（非数学加，不可交换）
mystring mystring::operator+(const mystring& mstr){
    mystring temp;
    temp.mydata = new char[mstr.mylen + this->mylen+1];
    temp.mylen = mylen + mstr.mylen;
    strcpy(temp.mydata, mydata);
    strcat(temp.mydata, mstr.mydata);
    return temp;
}

//重载'+='实现
mystring& mystring::operator+=(const mystring& mstr){
    mylen += mstr.mylen;
    char *newData = new char[mylen + 1];
    strcpy(newData, mydata);
    strcat(newData, mstr.mydata);
    delete [] mydata;
    mydata = newData;
    return *this;
}

//重载'=='实现
inline bool mystring::operator==(const mystring& mstr) const{
    if (mylen != mstr.mylen){
        return false;
    }
    return strcmp(mydata, mstr.mydata)==0;
}

//重载'!='实现
inline bool mystring::operator!=(const mystring& mstr) const{
    if (mylen != mstr.mylen){
        return true;
    }
    return strcmp(mydata, mstr.mydata)!=0;
}

//重载'< '实现
inline bool mystring::operator<(const mystring& mstr) const{
    if(this->mylen<mstr.mylen){
        return true;
    }
    return strcmp(mydata, mstr.mydata)<0;
}

//重载'> '实现
inline bool mystring::operator>(const mystring& mstr) const{
    if(this->mylen>mstr.mylen){
        return true;
    }
    return strcmp(mydata, mstr.mydata)>0;
}

//重载'<='实现
inline bool mystring::operator<=(const mystring& mstr) const{
    if(this->mylen<=mstr.mylen){
        return true;
    }
    return strcmp(mydata, mstr.mydata)<=0;
}

//重载'>='实现
inline bool mystring::operator>=(const mystring& mstr) const{
    if(this->mylen>=mstr.mylen){
        return true;
    }
    return strcmp(mydata, mstr.mydata)>=0;
}

//重载'[]'实现
inline char& mystring::operator[](size_t n) const{
    if (n >= mylen){
        return mydata[mylen-1];
    }else{
        return mydata[n];
    }
}

//myinsert实现
mystring& mystring::myinsert(size_t pos, const char* s){
    if(pos > mylen){
        pos = mylen;
    }
    char *p = new char[mylen + strlen(s) + 1];
    for (size_t i=0; i < mylen+strlen(s); i++){
        if (i<pos){
            p[i]=mydata[i];
        }else if(i<pos+strlen(s) && i>=pos){
            p[i]=s[i-pos];
        }else if(i>=pos+strlen(s)){
            p[i]=mydata[i-strlen(s)];
        }
    }
    delete [] mydata;
    mydata = p;
    mylen = mylen + strlen(s);
    mydata[mylen]='\0';
    return *this;
}

//mystrlen实现，有问题，待修，基本修完
unsigned long mystring::mystrlen(const char* mstr) const{
    return strlen(mstr);
}

unsigned long mystring::mystrlen(const mystring& mstr) const{
    return strlen(mstr.mydata);
}

unsigned long mystring::mystrlen(){
    return(this->mylen);
}

//show实现，重载输出运算符后可不用
void mystring::mystr_show() const{
    cout << "\"" << mydata << "\"" << endl;
}

//myfind实现
size_t mystring::myfind(const mystring& mstr) const{
    size_t pos, flag = 1;
    for(pos=0; pos<mylen; pos++){
        flag = 1;
        for(size_t i=0; i<mstr.mylen; i++){
            if(mydata[pos+i]!=mstr.mydata[i]){
                flag = 0;
                break;
            }
        }
        if(flag==1){
            return pos;
        }
    }
    return -1;
}

//upperstr实现，待修
void mystring::upperstr(){
    cout << "Upper \"" << mydata << "\" -> \"";
    //strupr(mystr);
    cout << mydata << "\"." << endl;
}

//mystrcpy实现，待修，修完了
mystring& mystring::mystrcpy(const char* mstr_ori){
    char* p = new char[strlen(mstr_ori)];
    strcpy(p, mstr_ori);
    delete [] mydata;
    mydata = p;
    return *this;
}

mystring& mystring::mystrcpy(mystring& mstr_ori){
    char* p = new char[strlen(mstr_ori.mydata)];
    strcpy(p, mstr_ori.mydata);
    delete [] mydata;
    mydata = p;
    return *this;
}

//myc_str实现
char* mystring::myc_str() const{
    return mydata;
}

//myswap实现
void mystring::myswap(mystring& mstr){
    char *temp = mstr.mydata;
    mstr.mydata = mydata;
    mydata = temp;
}
