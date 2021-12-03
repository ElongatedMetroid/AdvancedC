#include <stdio.h>

int main(void)
{
    int flags = 15;         // 0000 1111
    int mask = 182;         // 1011 0110

    flags = flags | mask;   // 1011 1111 

    printf("%d\n", flags);

    return 0;
}