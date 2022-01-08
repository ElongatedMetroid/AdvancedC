#include <stdio.h>

void funct1(int);
void funct2(int);

typedef void FuncType(int);

int main(){

    FuncType *funcPtr = NULL;

    funcPtr = funct1;

    (*funcPtr)(100);

    funcPtr = funct2;

    (*funcPtr)(200);

    return 0;
}

void funct1(int testarg){
    printf("funct1 got an argument of %d\n", testarg);
}

void funct2(int testarg){
    printf("funct2 got an argument of %d\n", testarg);
}