//for writing forrmatted output to a string
//this function is unsafe because of buffer overflow!
//int sprintf(char *string, const char *format, ...)
//sprintf(string, "%d %c %f", value, c, flt)

#include <stdio.h>

int main(){
    char string[100];
    int a = 10, b = 20, c = 0;
    c = a + b;

    sprintf(string, "The sum of %d and %d is %d", a, b, c);

    puts(string);
    return 0;
}