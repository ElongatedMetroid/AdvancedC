#include <stdio.h>

int main(void){
    int i = 15;
    int *ip = NULL;
    int **ipp = NULL;

    ip = &i;
    ipp = &ip;

    printf("--VALUE OF NORMAL INTEGER VARIABLE--\n");
    printf("**ipp = %d\n", **ipp);
    printf("*ip = %d\n", *ip);
    printf("i = %d\n\n", i);

    printf("--ADDRESS OF NORMAL INTEGER VARIABLE--\n");
    printf("Address of i = %p\n", &i);
    printf("ip = %p\n", ip);
    printf("*ipp = %p\n\n", *ipp);

    printf("--VALUE OF SINGLE POINTER VARIABLE--\n");
    printf("*ip = %d\n", *ip);
    printf("**ipp = %d\n\n", **ipp);

    printf("--ADDRESS OF SINGLE POINTER VARIABLE--\n");
    printf("Address of ip = %p\n", &ip);
    printf("ipp = %p\n\n", ipp);

    printf("--VALUE AND ADDRESS OF DOUBLE POINTER--\n");
    printf("ipp = %p\n", &ipp);
    printf("*ipp = %p\n", *ipp);

    return 0;
}