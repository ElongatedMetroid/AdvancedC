#define NDEBUG  //switch off assertions

#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(){
    double a, b, c;
    printf("Enter a pair of numbers (0 0 to quit): ");
    while (scanf("%lf%lf", &a, &b) == 2 && (a != 0 || b != 0)){
        c = a * a - b * b;
        assert(c >= 0);
        printf("Answer is %f\n", sqrt(c));
        puts("Next Pair of numbers: ");
    }

    puts("done");

    return 0;
}