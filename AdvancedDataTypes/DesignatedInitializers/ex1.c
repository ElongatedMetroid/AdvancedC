#include <stdio.h>

struct point {int x, y; };

int main()
{
    int numbers[100] = {1, 2, 3, [3 ... 9] = 10, [10] = 80, 15, [70] = 50, [42] = 400};

    for(int i = 0; i < 100; i++)
        printf("%d\n\n", numbers[i]);


    struct point p = { .y = 2, .x = 3}; //Declares x and y in different order
    struct point pts[5] = {[2].y = 5, [2].x = 6, [0].x = 2};

    for(int i = 0; i < 5; i++)
        printf("%d %d\n", pts[i].x, pts[i].y);

    return 0;
}