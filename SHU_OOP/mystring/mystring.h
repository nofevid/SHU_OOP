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

using namespace std;

class mystring{
public:
    //四大函数声明
    mystring(const char* mstr = "");                    //构造函数
    mystring (const mystring& mstr, size_t pos, size_t len);
    mystring (const mystring& mstr, size_t n);
    mystring (size_t n, char c);
   
    ~mystring();                                        //析构函数
    mystring(const mystring& mstr);                     //拷贝函数
   
    //重载'='声明
    mystring& operator=(const mystring& mstr);
    
    //重载'+'声明
    mystring operator+(const mystring& mstr);
    
    //重载'+='声明
    mystring& operator+=(const mystring& mstr);
    
    //重载'=='声明
    inline bool operator==(const mystring& mstr) const;
    
    //重载'!='声明
    inline bool operator!=(const mystring& mstr) const;
    
    //重载'< '声明
    inline bool operator<(const mystring& mstr) const;
    
    //重载'> '声明
    inline bool operator>(const mystring& mstr) const;
    
    //重载'<='声明
    inline bool operator<=(const mystring& mstr) const;
    
    //重载'>='声明
    inline bool operator>=(const mystring& mstr) const;
    
    //重载'[]'声明
    inline char& operator[](size_t n) const;
    
    //重载'>>'声明，实现
    friend istream& operator>>(istream& in, mystring& mstr){
        char tem[1000];  //简单的申请一块内存
        in >> tem;
        mstr.mylen = strlen(tem);
        mstr.mydata = new char[mstr.mylen + 1];
        strcpy(mstr.mydata, tem);
        return in;
    }
    
    //重载'<<'声明，实现
    friend ostream& operator<<(ostream& out, mystring& mstr){
        out << mstr.mydata;
        return out;
    }
    
    //功能函数声明
    unsigned long mystrlen(const char* mstr) const;
    unsigned long mystrlen(const mystring& mstr) const;
    unsigned long mystrlen();
    void upperstr();            //摊牌了，不想写了
    void mystr_show() const;    //cin已重载，可不用
    void myswap(mystring& mstr);
    size_t myfind(const mystring &mstr) const;
    char* myc_str() const;
    mystring& mystrcpy(const char* mstr_ori);
    mystring& mystrcpy(mystring& mstr_ori);
    mystring& myinsert(size_t pos, const char* s);
    
private:
    char *mydata;
    size_t mylen;
};
#endif /* mystring_h */
