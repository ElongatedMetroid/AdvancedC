#include <stdio.h>
#include <stdlib.h>

int main(void){
    char a[] = "123.456xyz", *end;
    double val = 0;

    val = strtod(a, &end);      //end points to x

    printf("Val = %lf\n", val);
    //there is also strtof but that is self explaitory (see atof.c)
    return 0;
}