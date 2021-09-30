//
//  20210926.h
//  SHU_OOP
//
//  Created by nofevid on 2021/9/26.
//

#ifndef _0210926_h
#define _0210926_h

#include <iostream>
#include "mystring.h"

using namespace std;

void experiment_20210926(){
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
}

#endif /* _0210926_h */
