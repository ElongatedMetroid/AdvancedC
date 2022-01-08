#include <stdio.h>

int somedisplay();

int main(){

    int (*funcPtr)();   //declare function pointer

    funcPtr = somedisplay;

    printf("\nAddress of function somedisplay is %p\n", funcPtr);

    (*funcPtr)();   //invoke function

    return 0;
}

int somedisplay(){
    printf("\n--Displaying some text--\n");
    return 0;
}