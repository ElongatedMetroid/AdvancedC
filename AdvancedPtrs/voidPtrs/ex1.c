#include <stdio.h>

int main(void){

    void *vp = NULL;

    int a = 100, *ip;
    float f = 12.2, *fp;
    char ch = 'a';

    vp = &a;
    //printf("%d\n", *vp); //does not work beacause a void pointer has not data type!
    printf("%d\n", *(int*)vp);
    vp = ip;
    vp = fp;

    return 0;
}