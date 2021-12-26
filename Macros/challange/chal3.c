#include <stdio.h>

#define CUBE(x) (x) * (x) * (x)
#define SQUARE(x) (x) * (x)

int main(){
    int x = 0;

    printf("Enter a numbers to square...\n");
    scanf("%d", &x);
    printf("%d", SQUARE(x));

    printf("\n\nEnter a number to cube...\n");
    scanf("%d", &x);
    printf("%d", CUBE(10));
}