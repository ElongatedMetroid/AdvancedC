#include <stdio.h>
#include <stdlib.h>

struct s
{
    int arraySize;   //a flexable array member can be declared only as the last member of a struct
    int array[];     //can only contain at most 1 flexible array member
};                   //the flexible array cannot be the only member of the struct

int main()
{
    int desiredSize = 5;
    struct s *ptr;
    
    ptr = malloc(sizeof(struct s) + desiredSize * sizeof(int));
    //allocates for struct, and the desiredSize of the amont of int's you want in the array (that is in the structure)
    
    return 0;
}