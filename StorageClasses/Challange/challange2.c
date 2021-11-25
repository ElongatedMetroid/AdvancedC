#include <stdio.h>

int sum(int num);

int main()
{
    printf("%d ", sum(25));
    printf("%d ", sum(15));
    printf("%d ", sum(30));
    printf("\n");
    return 0;
}

int sum(int num)
{
    static int i;
    int sum = num + i;

    i = sum;

    return  sum;
}