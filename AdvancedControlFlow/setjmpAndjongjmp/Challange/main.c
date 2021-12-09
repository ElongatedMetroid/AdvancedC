#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void error_recovery();

jmp_buf jmfBuf;

int main(void)
{
    while(1)
    {
        if(setjmp(jmfBuf))
        {
            printf("Back in main()\n");
            break;
        }
        else    
            error_recovery();
    }

    return 0;
}

void error_recovery()
{
    printf("Error\n");
    longjmp(jmfBuf, 1);
}