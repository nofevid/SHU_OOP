//
//  main.cpp
//  SHU_OOP
//
//  Created by nofevid on 2021/9/6.
//

#include <iostream>
#include <string.h>
#include <string>
//#include "20210906.h"
#include "20210908.h"
#include "20210915.h"
#include "20210922.h"
//#include "20210926.h"
#include "mystring/mystring.h"
#include "Myvector/Myvector.h"

using namespace std;

int main() {
    
//    start: int experiment_time = 0;
//    cin >> experiment_time;
//    string quit = "0";
//
//    //20210908实验内容
//    if (experiment_time == 20210908){
//        while (true){
//            cin >> coef[0][0] >> coef[0][1] >> coef[0][2];
//
//            flag = equation_solve(coef[0][0], coef[0][1], coef[0][2], &x1, &x2);
//
//            if (flag == 1){
//                cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
//            }
//            else if(flag == 0){
//                cout << "方程无解" << endl;
//            }
//
//            cin >> quit;
//            if (quit == "quit"){
//                goto start;
//            }
//
//        }
//    }
//
//
//    //20210915实验内容
//    if (experiment_time == 20210915){
//        int m(10);
//        Time t0, t1(10), t2(10, 20), t3(10, 20, 30), *p = &t0;
//        Time tArray[10];        Time *tPtr = &t1;        tPtr = new Time;
//        delete tPtr;
//        tPtr = new Time [m];
//        delete [] tPtr;
//
//        cout << sizeof(t0) <<endl;
//        t0.Show();
//        t0.set_time(8,30, 0);
//        p->Show();
//        t3.Show();
//
//        Complex num(11.22323, 0.001031192);
//
//        cout << "the complex number is " << num.Show1() << "." << endl;
//    }
//
//    //20210922实验内容
//    if (experiment_time == 20210922){
//        Cmplx<int> a, b(10);
//        Cmplx<char> c('A', 'B');
//        Cmplx<double> *p;
//        p = new Cmplx<double>(2.72, -3.14);
//
//        cout << "the complex number a is " << a.ShowCmplx1() << "." << endl;
//        cout << "the complex number b is " << b.ShowCmplx1() << "." << endl;
//        cout << "the complex number c is " << c.ShowCmplx1() << "." << endl;
//        cout << "the complex number d is " << p->ShowCmplx1() << "." << endl;
//    }
    
    //20210926实验内容
//    if (experiment_time == 20210926){
//        experiment_20210926();
//
//        cin >> quit;
//        if (quit == "quit"){
//            goto start;
//        }
//    }
    
    //20211013实验内容
//    if (experiment_time == 20211013){
//        mystring a("Hello");
//        mystring b="World";
//        mystring c;
//        c = a + " " + b;
//        c.mystr_show();
//
//        mystring d("abcdefg");
//        d.mystr_show();
//        d.mystrcpy(d, c);
//        cout << d.mystrcpy(d, c) << endl;           //mystrcpy有问题，待修
//        d.mystr_show();
//        d=c;
//        d.mystr_show();
//        c.mystr_show();
//        cout << a.mystrlen(a) << " " << b.mystrlen(b) << " " << c.mystrlen(c) << " " << d.mystrlen(d) << endl;
//    }
    
//    goto start;
    
//mystring类功能测试
    
//四大函数功能测试
    mystring a("Hello");
    mystring b="World";
    mystring c;
    cout << "a.mylen = " << a.mystrlen() << endl;
    cout << "a_strlen = " << strlen("Hello") << endl;
    cout << "b.mylen = " << b.mystrlen() << endl;
    cout << "b_strlen = " << strlen("World") << endl;
    cout << "c.mylen = " << c.mystrlen() << endl;
    cout << "c_strlen = " << strlen("") << endl;
    cout << endl;
    
    c = a + " " + b;
    c.mystr_show();
    cout << c << endl;
    cout << "c.mylen = " << a.mystrlen() << endl;
    cout << "c_strlen = " << strlen("Hello World") << endl;
    b = a + b;
    b.mystr_show();
    cout << b << endl;
    cout << "b.mylen = " << b.mystrlen() << endl;
    cout << "b_strlen = " << strlen("HelloWorld") << endl;
    a = a + " ";
    a.mystr_show();
    cout << a << endl;
    cout << "a.mylen = " << a.mystrlen() << endl;
    cout << "a_strlen = " << strlen("Hello ") << endl;
    cout << endl;

    a = "Hello";
    b = "World";
    mystring d("abcdefg");
    d.mystr_show();
    cout << d << endl;
    d.mystrcpy(c);
    d.mystr_show();
    cout << d << endl;
    d=c;
    d.mystr_show();
    c.mystr_show();
    cout << d << '\n' << c << endl;
    cout << "d.mylen = " << d.mystrlen() << endl;
    cout << "d_strlen = " << strlen("Hello World") << endl;
    cout << endl;
    
    cout << a.mystrlen(a) << " " << b.mystrlen(b) << " " << c.mystrlen(c) << " " << d.mystrlen(d) << endl;
    cout << a.mystrlen() << " " << b.mystrlen() << " " << c.mystrlen() << " " << d.mystrlen() << endl;
    cout << a.mystrlen(d) << " " << b.mystrlen(c) << " " << c.mystrlen(b) << " " << d.mystrlen(a) << endl;                                  //mystrlen有问题，待修（已修）（应该）
    cout << endl;
    
    string str_a("Hello World");
    string str_b(str_a, 5, 2);
    mystring e(c, 6, 8);
    mystring f(c, 0, 8);                        //len=8||9||10，结果有误，待修
    mystring g(7, 'b');
    mystring h(c, 2, 5);
    mystring i(c, 6);                           //重载错误，待修,已修
    cout << str_b << endl;
    e.mystr_show();
    f.mystr_show();
    g.mystr_show();
    h.mystr_show();
    i.mystr_show();
    cout << e << '\n' << f << '\n' << g << '\n' << h << '\n' << i << '\n' << endl;
    cout << endl;
    
//    mystring j;
//    cin >> j;
//    cout << j << endl;
    
    mystring k = "Hello C++.";
    k.myinsert(6, "World, I'm writing ");
    cout << k << endl;
    cout << k.myfind("World") << endl;
    cout << k.myc_str() << endl;
    cout << endl;
    
    cout << a << " \\ " << b << endl;
    a.myswap(b);
    cout << a << " \\ " << b << endl;
    
    
    return 0;
}
