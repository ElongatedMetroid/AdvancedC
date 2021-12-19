#include <stdio.h>
#include <stdarg.h>

double addAll(double numArgs, ...);

int main(){

    printf("%f\n", addAll(2.0, 10.0, 20.0));

    return 0;
}

double addAll(double numArgs, ...){
    va_list parg;
    double sum;
    double val;

    va_start(parg, numArgs);

    for(int i = 0; numArgs > i; i++){
        val = va_arg(parg, double);
        sum += val;
    }

    va_end(parg);

    return sum;
}