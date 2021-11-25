#include <stdio.h>

int main()
{
    size_t rows = 0;
    size_t columns = 0;

    printf("Enter the number of rows you want to store: ");
    scanf("%zd", &rows);
    printf("\nEnter the number of columns you want to store: ");
    scanf("%zd", &columns);

    float values[rows][columns];

    return 0;
}