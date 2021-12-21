#include <stdio.h>

union car{
    int i_value;
    float f_value;
    char value[40];     
};

int main(){

    union car car1, car2, *car3;
    //the union is 40 bytes because the biggest member is 40 bytes
    printf("Memory size occupied by car: %zu bytes\n", sizeof(car1));

    return 0;
}