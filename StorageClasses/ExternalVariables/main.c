#include <stdio.h>

int i = 5;
char text[255];

void foo(void);

int main()
{
    printf("%i ", i);
    foo();
    printf("%i\n", i);

    return 0;
}