//you can compile with -D to enable debug mode
//gcc -D DEBUG main.c -o main

#include <stdio.h>

#ifdef DEBON
    #define DEBUG(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
#endif //DEBON

int process(int i, int j, int k){

    DEBUG("process(%d, %d, %d)\n", i, j, k);

    return i+j+k;
}

int main(){
    int i, j, k, nread;

    nread = scanf("%d %d %d", &i, &j, &k);

    DEBUG("Number of integers read = %i\n", nread);
    DEBUG("i = %i, j = %i, k = %i\n", i, j, k);

    printf("%d\n", process(i, j, k));

    return 0;
}