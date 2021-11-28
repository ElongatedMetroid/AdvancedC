#include <stdio.h>
#include <malloc.h>

struct myArray
{
    int length;
    int array[];
};

int main()
{
    int requestedLen = 0;
    struct myArray *ptr;

    printf("enter the desired size of the array: ");
    scanf("%d", &requestedLen);

    ptr = malloc(sizeof(struct myArray) + requestedLen * sizeof(int));

    for(int i = 0; i < requestedLen; i++)
    {
        ptr->array[i] = i;
        printf("Array is equal to \"%i\"\n", ptr->array[i]);
    }

    return 0;
}