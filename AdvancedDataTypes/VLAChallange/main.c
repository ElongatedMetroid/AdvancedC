#include <stdio.h>

int main()
{
    size_t size = 0;
    int sum = 0;

    printf("Input enter the size of the array: ");
    scanf("%zd", &size);

    int array[size];

    for(int i = 0; i < size; i++)
    {
        printf("Enter Number %i: ", i);
        scanf("%i", &array[i]);
        sum += array[i];
    }

    printf("\n\nYour total is %d\n", sum);

    return 0;
}