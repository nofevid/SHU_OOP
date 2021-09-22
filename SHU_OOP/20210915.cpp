//
//  20210915.cpp
//  SHU_OOP
//
//  Created by nofevid on 2021/9/15.
//

#include "20210915.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//time类内部实现源代码
Time::Time(int hour, int minute, int second){   //构造函数
    h = hour;
    m = minute;
    s = second;
}

void Time::set_time(int hour, int minute, int second){
    h = hour;
    m = minute;
    s = second;
}

int Time::get_hour(){
    return h;
}

int Time::get_minute(){
    return m;
}

int Time::get_second(){
    return s;
}

void Time::Show(){
    cout << setfill('0') << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s << setfill(' ') << endl;
}

//complex类内部实现源代码
Complex::Complex(double real, double imag){
    re = real;
    im = imag;
}
double Complex::real()       const{
    return re;
}
double Complex::imag()       const{
    return im;
}
double Complex::radius()     const{
    return ra;
}
double Complex::angle()      const{
    return an;
}
void Complex::set1(double real, double imag){
    re = real;
    im = imag;
}
void Complex::set2(double radius, double angle){
    ra = radius;
    an = angle;
}

string Complex::Show1()        const{
    string num = to_string(re) + "+" + to_string(im) + "i";
    return num;
}
string Complex::Show2()        const{
    return 0;
}
