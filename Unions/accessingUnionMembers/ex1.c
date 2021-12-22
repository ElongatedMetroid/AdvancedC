#include <stdio.h>

union item{
    int code;
    double cost;
};

int main(){

    union item apple;

    //only one member is accessed at a time!
    apple.code = 1234;
    printf("Value of integer code: %d\n", apple.code);  //1234
    printf("Value of float cost: %f\n", apple.cost);    //0

    apple.cost = 99;
    printf("Value of integer code: %d\n", apple.code);  //0
    printf("Value of float cost: %f\n", apple.cost);    //99

    return 0;
}