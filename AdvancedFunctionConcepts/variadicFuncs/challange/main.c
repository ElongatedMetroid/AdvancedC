#include <stdio.h>
#include <stdarg.h>

double addAll(double numArgs, ...);

int main(){

    printf("%f\n", addAll(2.0, 10.0, 20.0));

    return 0;
}

double addAll(double numArgs, ...){
    va_list argPtr;
    va_start(argPtr, numArgs);

    double sum;

    for(int i = 0; numArgs > i; i++){
        sum += va_arg(argPtr, double);
    }
//Hello myself! - from your other computer
    va_end(argPtr);

    return sum;
}