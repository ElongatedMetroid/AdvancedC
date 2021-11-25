#include <stdio.h>

int i = 5;
char text[255];

void foo(void);

extern int number();    //allows you to use the number fuction without including a file

int main()
{
    printf("%i ", i);
    foo();
    printf("%i\n\n", i);

    printf("%i\n", number());

    return 0;
}