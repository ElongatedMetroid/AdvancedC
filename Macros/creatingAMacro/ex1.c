#include <stdio.h>
#include <stdarg.h>

#define PI 3.1415
#define CIRCLE_AREA(x) ((PI) * (x) * (x))

#define warning(...) fprintf(stderr, __VA_ARGS__)

int main(){

    double area = CIRCLE_AREA(4);

    //area = ((3.1415) * (4) * (4));

    printf("Area is %f\n", area);

    warning("%s: this program is here\n", "sus");

    return 0;
}