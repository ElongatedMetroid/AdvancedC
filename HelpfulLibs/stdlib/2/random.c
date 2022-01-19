#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(0));

    for(int i = 0; i < 10; i++)
        printf(" %d ", rand());    

    printf("\n");

    //by using the % operator you can generate numbers from 0 to n
    for(int i = 0; i < 10; i++)
        printf(" %d ", rand() % 5);    

    printf("\n");

    return 0;
}