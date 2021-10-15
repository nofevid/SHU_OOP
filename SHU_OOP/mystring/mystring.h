//
//  mystring.h
//  SHU_OOP
//
//  Created by nofevid on 2021/9/26.
//

#ifndef mystring_h
#define mystring_h

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

class mystring{
public:
    //四大函数声明
    mystring(const char *mstr = "");                    //构造函数
    mystring (const mystring& mstr, size_t pos, size_t len = mynpos);
    mystring (const mystring& mstr, size_t n);
    mystring (size_t n, char c);
   
    ~mystring();                                        //析构函数
    mystring(const mystring &mstr);                       //拷贝函数
   
    //重载'='，在体内完成
    mystring & operator=(const mystring &mstr){
        if(&mstr != this){
            delete [] mydata;
            mydata = new char[mstr.mylen + 1];
            strcpy(mydata, mstr.mydata);
            mylen = mstr.mylen;
        }
        return *this;
    }
    
    //重载'+'
//    mystring operator+(char n){
//        mystring temp = new char[strlen(mstr.mystr) + 2];
//
//        return temp;
//    }
    
    mystring operator+(const mystring &mstr){
        mystring temp;
        temp.mydata = new char[mstr.mylen + this->mylen];
        temp.mylen = mylen + mstr.mylen;
        strcpy(temp.mydata, mydata);
        strcat(temp.mydata, mstr.mydata);
        return temp;
    }
    
    //重载'-'
    
    //功能函数声明
    unsigned long mystrlen(const char *mstr) const;
    unsigned long mystrlen(const mystring &mstr) const;
    unsigned long mystrlen();
    void upperstr();
    void mystr_show() const;
    char c_mystr() const;
    char *mystrcpy(char *mstr_des, const char *mstr_ori);
    char *mystrcpy(mystring mstr_des, mystring mstr_ori);
    
private:
    char *mydata;
    size_t mylen;
    static const size_t mynpos = -1;
};

#endif /* mystring_h */
