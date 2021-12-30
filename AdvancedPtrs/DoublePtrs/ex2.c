#include <stdio.h>

int main(){
    int a = 10;

    int *p1 = NULL;
    int **pp2 = NULL;

    p1 = &a;        //p1 = a(10)
    pp2 = &p1;      //pp2 now points to p1 witch points to a (10)

    printf("Address of a = %p\n", &a);
    printf("Address of p1 = %p\n", &p1);
    printf("Address of pp2 = %p\n\n", &pp2);

    printf("Value at the address stored by pp2 =  %p\n", *pp2);     //same as a's address
    printf("Value at the address stored by p1 = %d\n\n", *p1);
    printf("Value of **pp2 = %d\n", **pp2);

    return 0;
}