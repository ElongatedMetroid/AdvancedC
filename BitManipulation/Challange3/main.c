#include <stdio.h>

int main(void)
{
    unsigned int numberInput;   //1010
    unsigned int bitToCheck;    //0100
    unsigned int bitStatus;     //0000

    printf("Enter any number: ");
    scanf("%d", &numberInput);

    bitToCheck = 32;
    while(31 < bitToCheck)
    {
        printf("Enter the n'th bit to check and set (0-31): ");
        scanf("%d", &bitToCheck);
        if(bitToCheck > 31)
            printf("\nThe bit to check has to be in the range of 0-31\bitStatus");
    }

    bitStatus = (numberInput >> bitToCheck) & 1;    //  1010 >> 2 = 0010 & 0001 = 0
    printf("The %d bit is set to %d\n", bitToCheck, bitStatus);

    printf("\nBit Set Successfully.\n\n");

    printf("Number before setting %d bit: %d (in decimal)\n", bitToCheck, numberInput);
    numberInput = (1 << bitToCheck) | numberInput;  // 0001 << 2 = 0100 | 1010 = 1110
    printf("Number after setting %d bit: %d (in decimal)\n", bitToCheck, numberInput);


    return 0;
}