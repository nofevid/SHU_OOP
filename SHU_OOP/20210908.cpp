//
//  20210908.cpp
//  SHU_OOP
//
//  Created by nofevid on 2021/9/8.
//

//#include "20210908.hpp"
#include <cmath>

int equation_solve(float a,float b,float c,float *x1,float *x2){
    float delta = b*b - 4*a*c;
    
    if (delta > 0){
        *x1 = (-b + pow(delta, 0.5)) / (2 * a);
        *x2 = (-b - pow(delta, 0.5)) / (2 * a);
        
        return 1;
    }
    else if (delta == 0){
        *x1 = (-b) / (2 * a);
        *x2 = *x1;
        
        return 1;
    }
    else{
        return 0;
    }
}
