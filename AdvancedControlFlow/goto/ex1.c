#include <stdio.h>

int main()
{   
    int i;
    const int maxInput = 5;
    double number, average, sum = 0.0;

    for(i = 1; i <= maxInput; ++i)      //gets average of five numbers unless there less than 0.0
    {
        printf("%d. Enter a number: ", i);
        scanf("%lf", &number);

        if(number < 0.0)                //checks if less then 0.0
            goto jump;                  //Jumps out of loop if true
        
        sum += number;
    }

    jump:
        average = sum/(i-1);
        printf("Sum = %.2f\n", sum);
        printf("Average = %.2f", average);

    return 0;
}