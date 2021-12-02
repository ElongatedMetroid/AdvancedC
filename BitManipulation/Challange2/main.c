#include <stdio.h>

long long int DecToBin(int dec);
void OnesComplement();
void AND();
void OR();
void XOR();
void LeftShift();
void RightShift();

int value1, value2;

int main(void)
{
    printf("Enter an integer: ");
    scanf("%255d", &value1);
    printf("\nEnter another integer: ");
    scanf("%d", &value2);
    printf("\n");

    OnesComplement();
    AND();
    OR();
    XOR();
    LeftShift();
    RightShift();

    return 0;
}

long long int DecToBin(int dec)
{
    long long bin = 0;
    int remainder, i = 1;

    while(dec != 0)
    {
        remainder = dec%2;
        dec = dec / 2;
        bin += remainder * i;
        i *= 10;
    }

    return bin;
}

void OnesComplement()
{
    int result;
    result = ~(value1);
    printf("The result of applying the ~ operator on number %d (%lld) is: %lld\n", value1, DecToBin(value1), DecToBin(result));
    result = ~(value2);
    printf("The result of applying the ~ operator on number %d (%lld) is: %lld\n", value2, DecToBin(value2), DecToBin(result));
}

void AND()
{
    int result;
    result = value1 & value2;
    printf("The result of applying the & operator on number %d (%lld) and number %d (%lld) is: %lld\n", value1, DecToBin(value1), value2, DecToBin(value2), DecToBin(result));
}

void OR()
{
    int result;
    result = value1 | value2;
    printf("The result of applying the | operator on number %d (%lld) and number %d (%lld) is: %lld\n", value1, DecToBin(value1), value2, DecToBin(value2), DecToBin(result));
}

void XOR()
{
    int result;
    result = value1 ^ value2;
    printf("The result of applying the ^ operator on number %d (%lld) and number %d (%lld) is: %lld\n", value1, DecToBin(value1), value2, DecToBin(value2), DecToBin(result));
}

void LeftShift()
{
    unsigned int result;
    result = value1 << 2;

    printf("The result of applying the left shift operator on number %d (%lld) by 2 places is number: %d (%lld)\n", value1, DecToBin(value1), result, DecToBin(result));

    result = value2 << 2;
    printf("The result of applying the left shift operator on number %d (%lld) by 2 places is number: %d (%lld)\n", value2, DecToBin(value2), result, DecToBin(result));
}

void RightShift()
{
    unsigned int result;
    result = value1 >> 2;

    printf("The result of applying the right shift operator on number %d (%lld) by 2 places is number: %d (%lld)\n", value1, DecToBin(value1), result, DecToBin(result));

    result = value2 >> 2;
    printf("The result of applying the right shift operator on number %d (%lld) by 2 places is number: %d (%lld)\n", value2, DecToBin(value2), result, DecToBin(result));
}
