//pointer -> pointer -> variable

#include <stdio.h>

int main(){

    int **ipp = NULL;

    int i = 5, j = 6, k = 7;

    int *ip1 = &i, *ip2 = &j;

    ipp = &ip1; //*ipp is ip1, **ipp is i (5)

    printf("ipp = %p\n", ipp);
    printf("**ipp = %d\n\n", **ipp);

    *ipp = ip2; //the pointer pointed to by ipp now points to j; ip1 now points at j(6)

    printf("*ipp = %p\n", *ipp);
    printf("**ipp = %d\n\n", **ipp);

    *ipp = &k; //(we have to use address of operator because k is NOT a pointer)

    printf("*ipp = %p\n", *ipp);
    printf("**ipp = %d\n\n", **ipp);

    return 0;
}