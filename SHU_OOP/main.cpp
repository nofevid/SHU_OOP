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

void mystring_test_basic(){
//四大函数功能测试
    mystring a("Hello");
    mystring b="World";
    mystring c;
    cout << "a = \"" << a << "\"" << endl;
    cout << "a.mylen = " << a.mystrlen() << endl;
    cout << "a_strlen = " << strlen("Hello") << endl;
    cout << "b = \"" << b << "\"" << endl;
    cout << "b.mylen = " << b.mystrlen() << endl;
    cout << "b_strlen = " << strlen("World") << endl;
    cout << "c = \"" << c << "\"" << endl;
    cout << "c.mylen = " << c.mystrlen() << endl;
    cout << "c_strlen = " << strlen("") << endl;
    cout << endl;
    
    c = a + " " + b;
    cout << "c = a + \" \" + b =\"" << c << "\"" << endl;
    cout << "c.mylen = " << a.mystrlen() << endl;
    cout << "c_strlen = " << strlen("Hello World") << endl;
    b = a + b;
    cout << "b = a + b = \"" << b << "\"" << endl;
    cout << "b.mylen = " << b.mystrlen() << endl;
    cout << "b_strlen = " << strlen("HelloWorld") << endl;
    a = a + " ";
    cout << "a = a + \" \" = \"" << a << "\"" << endl;
    cout << "a.mylen = " << a.mystrlen() << endl;
    cout << "a_strlen = " << strlen("Hello ") << endl;
    a += c;
    cout << "a += c = \"" << a << "\"" << endl;
    cout << "a.mylen = " << a.mystrlen() << endl;
    cout << "a_strlen = " << strlen("Hello Hello World") << endl;
    cout << endl;
    
    cout << "input: ";
    mystring j;
    cin >> j;
    cout << "output mystring j = \"" << j << "\"" << endl;
    cout << endl;

    a = "Hello";
    b = "World";
    mystring d("abcdefg");
    cout << "d = \"" << d << "\"" << endl;
    d.mystrcpy(c);
    cout << "mystrcpy(c), d = \"" << d << "\"" << endl;
    if(d==c){
        cout << "d = c, d = \"" << d << "\", c= \"" << c << "\"" << endl;
        cout << "d.mylen = " << d.mystrlen() << endl;
        cout << "d_strlen = " << strlen("Hello World") << endl;
    }
    cout << endl;
    
    mystring f(c, 0, 8);                        //len=8||9||10，结果有误，待修
    mystring g(c, 2, 5);
    mystring h(c, 6);                           //重载错误，待修,已修
    mystring i(7, 'b');
    cout << "c = \"" << c << "\"" << '\n'
         << "f = \"" << f << "\"" << '\n'
         << "g = \"" << g << "\"" << '\n'
         << "h = \"" << h << "\"" << '\n'
         << "i = \"" << i << "\"" << '\n';
    cout << endl;
    
    mystring k = "Hello C++.";
    k.myinsert(6, "World, I'm writing ");
    cout << "insert mystring \"World, I'm writing \" to mystring k = \"Hello C++.\",\n get j = \"" << k << "\"\n" << endl;
    cout << "we can find \"world\" in k starting from position " << k.myfind("World") << "\n" << endl;
    cout << "convert k to c_str, get \"" << k.myc_str() << "\"\n" << endl;
    k.myinsert(29, "I've written lots of bugs.");
    cout << "insert \"I've written lots of bugs.\" to the end of k, get \"" << k.myc_str() << "\"" << endl;
    cout << endl;
    
    cout << "before swap: a = \"" << a << "\", b = \"" << b << "\"" << endl;
    a.myswap(b);
    cout << "after  swap: a = \"" << a << "\", b = \"" << b << "\"" << endl;
    cout << endl;
    
    mystring l("abcdefghijklmn");
    cout << "l = \"" << l << "\"" << endl;
    l.myupper(l);
    cout << "upper all letters by using fun(myupper(l)), l = \""<< l << "\"" << endl;
    l="abcdefghijklmn";
    l.myupper(l, 1);
    cout << "upper the second letter by using fun(myupper(l, 1)), l = \""<< l << "\"" << endl;
    l[3]='D';
    cout << "upper the forth letter by using [], l = \""<< l << "\"" << endl;
    cout << endl;
}

void mystring_test_error(){
    mystring a = "Hello World";
    cout << "a = \"" << a << "\"" << endl;
    mystring *b, *c, *e;
    
    for(size_t pos = 1; pos <= a.mystrlen(); pos++){
        b = new mystring(a, 0, pos);
        cout << "b[" << pos << "] = \"" << *b << "\""<< endl;
        delete b;
    }
    
    cout << endl;
    
    for(size_t pos = 1; pos <= a.mystrlen(); pos++){
        c = new mystring(a, pos);
        cout << "c[" << pos << "] = \"" << *c << "\""<< endl;
        delete c;
    }
    cout << endl;
    
    mystring d = "acemnorsuvwxz";
    for(size_t pos = 0; pos <= d.mystrlen(); pos++){
        e = new mystring;
        *e = d.myinsert(pos, "[]");
        cout << "e[" << pos << "] = \"" << *e << "\""<< endl;
        delete e;
        d = "acemnorsuvwxz";
    }
    cout << endl;

    for(size_t pos = 0; pos < d.mystrlen(); pos++){
        e = new mystring;
        *e = d.myupper(d, pos);
        cout << "e[" << pos << "] = \"" << *e << "\""<< endl;
        delete e;
        d = "acemnorsuvwxz";
    }
}

int main() {
    //mystring自定义字符串类测试
    cout << "mystring_test_basic" << endl << endl;;
//    mystring_test_basic();
    cout << endl;
    cout << "mystring_test_error" << endl << endl;
    mystring_test_error();
    return 0;
    
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

}

