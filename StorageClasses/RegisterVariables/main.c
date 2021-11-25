#include <stdio.h>

int main()
{
    register int x; //register variable

    //DO NOT use the ampersand with register variables, as they dont hold a memory location
    //like this "int *a = &x"

    for(x = 1; x <= 15; x++)
        printf("\n%d", x);

    return 0;
}