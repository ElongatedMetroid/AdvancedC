//running 'gcc main.c' will generate a file called a.out

//to name your executable you can use the -o flag like 'gcc main.c -o main', this will generate an executable called main

//using the -c option you can make the compiler generate a .o file
//gcc -c main.c will generate main.o

//to make the compiler show all the warnings use -Wall
//gcc -Wall main.c -o main.out

//you can use -E and > to generate what the preprocesser generates and direct it to another file
//gcc -E main.c > preprocessor

//you can use -S to generate the assembly code
//gcc -S main.c

//by using -save-temps the compiler will save all the temp files
//gcc -save-temps main.c -o main

#include <stdio.h>

int main(){
    printf("Hello World!\n");
    return 0;
}