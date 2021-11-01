//
//  rsa-mystring.h
//  SHU_OOP
//
//  Created by nofevid on 2021/10/27.
//

#ifndef rsa_mystring_h
#define rsa_mystring_h
#include "mystring/mystring.h"

class rsa_mystring : public mystring{
public:
    rsa_mystring(const char* c="Let's do rsa encryt.");
    mystring encrypt(const rsa_mystring& C, int E);
    mystring decrypt();
private:
    int e = 65537;
    unsigned long long p, q;
}

#endif /* rsa_mystring_h */
