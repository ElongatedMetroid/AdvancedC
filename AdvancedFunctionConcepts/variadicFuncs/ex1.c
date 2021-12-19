//one function could have n number of arguments

#include <stdio.h>
#include <stdarg.h>

double average(double v1, double v2, ...);

int main(){
    double v1 = 10.5, v2 = 2.5;
    int num1 = 6, num2 = 5;
    long num3 = 12l, num4 = 20l;

    printf("Average = %.2f\n", average(v1, 3.5, v2, 4.5, 0.0));

    return 0;
}

double average(double v1, double v2, ...){
    va_list parg;       //declare object to hold argument
    double sum = v1 + v2;
    double value = 0.0;

    int count = 2;
    va_start(parg, v2);   //initialize parg to argument list

    while((value = va_arg(parg, double)) != 0.0){   //retrive next argument everytime until it hits 0
        sum += value;                               //add the next argument to the sum
        ++count;
    }

    va_end(parg);

    return sum/count;
}