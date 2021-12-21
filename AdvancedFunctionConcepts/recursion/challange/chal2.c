#include <stdio.h>

int gcd(int n1, int n2);

int main(){
    printf("%i", 50%10);
    printf("%i\n", gcd(10, 50));

    return 0;
}

int gcd(int n1, int n2){
    if(n2 > n1)                 
        return gcd(n2, n1);
    if(n2 == 0)
        return n1;
    else
        return gcd(n2, n1 % n2);
}