#include <stdio.h>
#include <malloc.h>

void allocateMemory(int **ptr){
    *ptr = (int*)malloc(sizeof(int));
}

int main(){
    int *ptr = NULL;

    allocateMemory(&ptr);

    *ptr = 5;

    printf("*ptr = %d\n", *ptr);

    free(ptr);

    return 0;
}