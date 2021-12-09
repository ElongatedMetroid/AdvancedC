#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

void myFunction()
{
    printf("in myFunction()\n");
    longjmp(buf,1);

    //Not Reached
    printf("You will never see this, because I longjmp'd");
}

int main(void)
{
    if(setjmp(buf))
        printf("back in main\n");
    else   
    {
        printf("first time through\n");
        myFunction();
    }

    return 0;
}