#include <stdio.h>

#define PRNT(a, b)\
    printf("value1 = %d\n", a);\
    printf("value2 = %d\n", b);

int main(void){

    //before the program is compiled PRNT(a, b) gets replaced with
    //printf("value1 = %d\n", a);
    //printf("value2 = %d\n", b);

    PRNT(15, 25);

    return 0;
}