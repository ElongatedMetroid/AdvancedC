#include <stdio.h>
#include <malloc.h>

void pfoo(int *ptr){
    int a = 5;
    //*ptr = a;   //you CAN change the value of what the pointer is pointing to but not the pointer itself
    ptr = &a;   //local pointer is now pointing to a different address, not the one you passed in
}   //this just changes what the local copy points to

//^to fix this we can use a double pointer as shown
void ppfoo(int **ptr){
    int a = 5;
    *ptr = &a;
}

int main(){
    int *ptr = NULL;
    ptr = (int*)malloc(sizeof(int));
    *ptr = 10;

    pfoo(ptr);
    printf("*ptr is equal to %d\n", *ptr);

    ppfoo(&ptr);
    printf("*ptr is equal to %d\n", *ptr);

    free(ptr);

    return 0;
}