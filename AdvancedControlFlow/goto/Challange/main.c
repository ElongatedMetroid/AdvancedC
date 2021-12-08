#include <stdio.h>

int main()
{
    int i;

    printf("    *");
    i++;
    goto newline;    

    linetwo:
    printf("   * *");
    i++;
    goto newline;

    linethree:
    printf("  *   *");
    i++;
    goto newline;

    linefour:
    printf(" *     *");
    i++;
    goto newline;

    linefive:
    printf("*********\n");
    return 0;

    newline:
    printf("\n");
    if(i == 1)
        goto linetwo;
    else if(i == 2)
        goto linethree;
    else if(i == 3)
        goto linefour;
    else if(i == 4)
        goto linefive;
}