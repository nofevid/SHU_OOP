//
//  20210926.h
//  SHU_OOP
//
//  Created by nofevid on 2021/9/26.
//

#ifndef _0210926_h
#define _0210926_h

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

class mystring{
public:
    //四大函数声明
    mystring(const char *mstr = "NoString");
    ~mystring();
    mystring(const mystring &ms);
    mystring & operator=(const mystring &ms){           //重载‘=’，在体内完成
        if(&ms != this){
            delete [] mystr;
            mystr = new char[strlen(ms.mystr) + 1];
            strcpy(mystr, ms.mystr);
        }
        return *this;
    }
    
    //功能函数声明
    unsigned long mystrlen() const;
    void upperstr();
    void ms_show() const;
    
private:
    char *mystr;
};

#endif /* _0210926_h */
