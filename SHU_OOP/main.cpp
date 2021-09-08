//
//  main.cpp
//  SHU_OOP
//
//  Created by nofevid on 2021/9/6.
//

#include <iostream>
//#include "20210906.h"
#include "20210908.h"

using namespace std;

int main() {
    
    //20210908实验内容
    cin >> coef[0][0] >> coef[0][1] >> coef[0][2];
    
    flag = equation_solve(coef[0][0], coef[0][1], coef[0][2], &x1, &x2);
    
    if (flag == 1){
        cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if(flag == 0){
        cout << "方程无解" << endl;
    }
    
    return 0;
}
