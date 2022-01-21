#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
    srand(time(NULL));

    for(int i = 0; i < 50; i++)
        printf(" %0.4lf\n ", (rand() % 2001 - 1000) / 2.e3);    

    return 0;
}