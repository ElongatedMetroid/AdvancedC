#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
    &ptr = 0xaaaaa;
    ptr = 0xfffff;
    0xfffff = 6

    &ptr1 = 0xbbbbb;
    ptr1 = 0xfffff;
*/

void pfoo(char *ptr){
    ptr = malloc(255);          //allocates memory for the copy
    strcpy(ptr, "Hello, World!");
}

void ppfoo(char **ptr){
    *ptr = malloc(255);     //allocates memory for
    strcpy(*ptr, "Hello, World!");
}

int main(){

    char *ptr = NULL;

    pfoo(ptr);
    //printf("%s\n", ptr); <--- wont work because its trying to print out NULL

    //free(ptr); <--- has an error because the memory was allocated for the copy, and there is nothing to free

    ppfoo(&ptr);
    printf("%s\n", ptr);
    
    free(ptr);

    return 0;
}