//
//  20210922.hpp
//  SHU_OOP
//
//  Created by nofevid on 2021/9/22.
//

#ifndef _0210922_h
#define _0210922_h

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template <typename TYPE> class Cmplx        //类模版声明
{                                           //TYPE为待定数据类型，或称为形式数据类型
public:
    Cmplx(const TYPE real = 0, const TYPE imag = 0);
    TYPE get_real()       const;
    TYPE get_imag()       const;
    TYPE get_radius()     const;
    TYPE get_angle()      const;
    void set_complex1(TYPE real, TYPE imag);
    void set_complex2(TYPE radius, TYPE angle);
    string ShowCmplx1()        const;
    string ShowCmplx2()        const;
private:
    TYPE re, im, ra, an;
};

//在类声明体外描述成员函数要进行的操作
template <typename TYPE> Cmplx<TYPE>::Cmplx(const TYPE real, const TYPE imag){
    re = real;
    im = imag;
}

template <typename TYPE> TYPE Cmplx<TYPE>::get_real() const{
    return re;
}

template <typename TYPE> TYPE Cmplx<TYPE>::get_imag() const{
    return im;
}

template <typename TYPE> TYPE Cmplx<TYPE>::get_radius() const{
    return ra;
}

template <typename TYPE> TYPE Cmplx<TYPE>::get_angle() const{
    return an;
}

template <typename TYPE> void Cmplx<TYPE>::set_complex1(TYPE real, TYPE imag){
    re = real;
    im = imag;
}

template <typename TYPE> void Cmplx<TYPE>::set_complex2(TYPE radius, TYPE angle){
    ra = radius;
    an = angle;
}

template <typename TYPE> string Cmplx<TYPE>::ShowCmplx1() const{
    string num;
    if (im != 0){
        if (im > 0){
            num = to_string(re) + "+" + to_string(im) + "i";
        }else if(im < 0){
            num = to_string(re) + "-" + to_string(-im) + "i";
        }
    }else{
        num = to_string(re);
    }
    return num;
}

template <typename TYPE> string Cmplx<TYPE>::ShowCmplx2() const{
    string num = to_string(re) + "+" + to_string(im) + "i";
    return num;
}

#endif /* _0210922_h */
