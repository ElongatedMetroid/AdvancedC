#include <stdio.h>

int fun();

int main()
{
    for(int i; i < 6; i++)
        fun();

    /*The output is "1 2" because it does not get 
    reinitialized everytime it is called*/

    return 0;
}

static int fun()    //stactic functions CAN'T be called outside of the file its declared in
{
    //statics are not reinitialized everytime they are called
    static int count = 0;
    
    int localVar = 0;

    printf("automatic = %d, static = %d\n", localVar, count);

    localVar++;
    count++;
    return count;
}