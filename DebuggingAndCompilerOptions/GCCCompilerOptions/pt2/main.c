//to link libraries use -l
//gcc -Wall main.c -o main -l m
//this links the math library

//you can do 'ldd a.out' to display a list of the shared libraries that it needs 

#include <stdio.h>

int main(){

    printf("Hello World!\n");

    return 0;
}