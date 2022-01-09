//to make the lib do the following
//gcc -c libCode.c -o lib_mylib.o
//ar rcs lib_mylib.a lib_mylib.o
//ar -t lib_mylib.a

#include <stdio.h>

void fun(void){
    printf("fun() called from a static library!\n");
}