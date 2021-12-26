#include <stdio.h>

#define ADDNUMS(x, y)\
    (x) + (y)

int main(){
    int x, y;

    printf("Enter two numbers seperated by spaces...\n");

    scanf("%d %d", &x, &y);

    int sum = ADDNUMS(x, y);

    printf("%d\n", sum);

    return 0;
}