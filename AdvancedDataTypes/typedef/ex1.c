#include <stdio.h>

#define int_pointer int *

int_pointer chalk, cheese; //same as int *chalk, cheese;
                           //typedef prevents this 
typedef int bannana;

//unsigned bannana i; is illegal

//typedef's will add readability to your code
//does not define a new type, only a new type name

typedef int * i_pointer;

int main()
{
    i_pointer p; //same as int*p

    i_pointer a, *b; //same as int *a, **b;

    i_pointer myArray[10]; //same as int *myArray[10];

    return 0;
}