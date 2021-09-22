//
//  20210915.hpp
//  SHU_OOP
//
//  Created by nofevid on 2021/9/15.
//

#ifndef _0210915_h
#define _0210915_h

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Time类声明
class Time
{
public:
    Time(int hour = 0, int minute = 0, int second = 0);
    void set_time(int hour, int minute, int second);
    int get_hour();
    int get_minute();
    int get_second();
    void Show();
    
private:
    int h, m, s;
};

//Complex类声明
class Complex
{
public:
    Complex(double real = 0,double imag = 0);
    double real()       const;
    double imag()       const;
    double radius()     const;
    double angle()      const;
    void set1(double real, double imag);
    void set2(double radius, double angle);
    string Show1()        const;
    string Show2()        const;
private:
    double re, im, ra, an;
};

#endif /* _0210915_h */
