/*
profiling is a dynamic program analysis that measures
    *space (memory)
    *time complexity of a program (efficiency)
    *usage of particular instructions
    *the frequency and duration of function calls

This gives you the information to optimize your program

Use -pg to enable profiling
gcc -pg test1.c test2.c

it will then generate a gmon.out file

gprof a.out gmon.out > analysis.txt

valgrind --leak-check=yes a.out
*/

#include <stdio.h>

void new_func1(void);

void func1(void){
    printf("Inside func1\n");

    for(int i = 0; i<0xffffffff; i++);

    new_func1();

    return;
}

static void func2(void){
    printf("Inside func2\n");

    for(int i = 0; i < 0xffffffaa; i++);
    
    return;
}

int main(void){
    printf("Inside main()\n");

    for(int i = 0; i<0xffffff; i++);
    func1();
    func2();

    return 0;
}