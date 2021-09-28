//
//  main.cpp
//  SHU_OOP
//
//  Created by nofevid on 2021/9/6.
//

#include <iostream>
#include <string>
//#include "20210906.h"
#include "20210908.h"
#include "20210915.h"
#include "20210922.h"
#include "20210926.h"

using namespace std;

int main() {
    
    start: int experiment_time = 0;
    cin >> experiment_time;
    string quit = "0";
    
    //20210908实验内容
    if (experiment_time == 20210908){
        while (true){
            cin >> coef[0][0] >> coef[0][1] >> coef[0][2];
            
            flag = equation_solve(coef[0][0], coef[0][1], coef[0][2], &x1, &x2);
    
            if (flag == 1){
                cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
            }
            else if(flag == 0){
                cout << "方程无解" << endl;
            }
            
            cin >> quit;
            if (quit == "quit"){
                goto start;
            }
            
        }
    }
    
    
    //20210915实验内容
    if (experiment_time == 20210915){
        int m(10);
        Time t0, t1(10), t2(10, 20), t3(10, 20, 30), *p = &t0;
        Time tArray[10];        Time *tPtr = &t1;
        tPtr = new Time;
        delete tPtr;
        tPtr = new Time [m];
        delete [] tPtr;
        
        cout << sizeof(t0) <<endl;
        t0.Show();
        t0.set_time(8,30, 0);
        p->Show();
        t3.Show();
        
        Complex num(11.22323, 0.001031192);
        
        cout << "the complex number is " << num.Show1() << "." << endl;
    }
    
    //20210922实验内容
    if (experiment_time == 20210922){
        Cmplx<int> a, b(10);
        Cmplx<char> c('A', 'B');
        Cmplx<double> *p;
        p = new Cmplx<double>(2.72, -3.14);
        
        cout << "the complex number a is " << a.ShowCmplx1() << "." << endl;
        cout << "the complex number b is " << b.ShowCmplx1() << "." << endl;
        cout << "the complex number c is " << c.ShowCmplx1() << "." << endl;
        cout << "the complex number d is " << p->ShowCmplx1() << "." << endl;
    }
    
    //20210926实验内容
    if (experiment_time == 20210926){
        while (true){
            char str[10] = "Tom", *ptr = new char[10];
            strcpy(ptr, "Jerry");
            mystring ms1(str), ms2(ptr), ms3("Snoopy");
            ms1.ms_show();
            cout << ms1.mystrlen() << endl;
            ms2.ms_show();
            cout << ms2.mystrlen() << endl;
            ms3.ms_show();
            cout << ms3.mystrlen() << endl;
            cout << "Do something..." << endl;
            strcpy (str, "Winnie");
            ms1.ms_show();
            delete [] ptr;
            ms2.ms_show();
            ms3.upperstr();
            ms3.ms_show();
            mystring ms4 = ms1;
            ms2 = ms1;
            ms2.ms_show();
            ms4.ms_show();
            
            
            
            cin >> quit;
            if (quit == "quit"){
                goto start;
            }
            
        }
    }
    
    goto start;
    
    return 0;
}
