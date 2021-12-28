#include <stdio.h>

void new_func1(void){
    printf("Inside new_func1()\n");

    for(int i = 0; i<0xffffffee; i++);

    return;
}