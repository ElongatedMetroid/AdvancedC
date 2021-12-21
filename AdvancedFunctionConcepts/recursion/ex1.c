#include <stdlib.h>
#include <stdio.h>

int factorial(int n);

int main(){

    for(int j = 0; j < 8; ++j)
        printf("%d! = %d\n", j, factorial(j));

    return 0;
}

int factorial(int n){
    int result = 0;

    if(n == 0)
        result = 1;
    else   
        result = n * factorial (n - 1);

    return result;
}

/*
factorial(3) = 3 * factorial(2)
    =3 * 2 * factorial(1)
    =3 * 2 * 1 * factorial(0)
    =3 * 2 * 1 * 1
    =6
*/