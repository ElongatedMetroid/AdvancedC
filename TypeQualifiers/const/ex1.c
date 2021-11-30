#include <stdio.h>

int main(void)
{
    const double pi = 3.141592654;

    //pi = pi * 2 is illegal

    const int days[12] = {31, 28, 31, 30};

    typedef const int zip;

    const zip q = 8; //basicaly saying "const const zip q = 8" but the compiler does not care

    /*POINTERS*/
    const float *f; //f points to a constant float value

    int * const i;  //i is a constant pointer

    const char * const c;   //nothing can change

}