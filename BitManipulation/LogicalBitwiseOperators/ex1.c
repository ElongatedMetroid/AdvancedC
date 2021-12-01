#include <stdio.h>

void ANDOperator();
void OROperator();
void XOROperator();
void OnesAndTwosComplement();

int main()
{
    ANDOperator();
    OROperator();
    XOROperator();
    OnesAndTwosComplement();
    return 0;
}

void ANDOperator()
{
    short int w1 = 25;
    short int w2 = 77;
    short int w3 = 0;

    w3 = w1 & w2;
    printf("%d\n", w3);

    /* & OPERATOR
    00011001 = 25   
    01001101 = 77
    --------
    00001001 = 9
    */
}

void OROperator()
{
    short int w1 = 147;
    short int w2 = 61;
    short int w3 = 0;

    w3 = w1 | w2;
    printf("%d\n", w3);

    /* | OPERATOR
    10010011 = 147   
    00111101 = 61
    --------
    10111111 = 191
    */
}

void XOROperator()
{
    short int w1 = 147;
    short int w2 = 61;
    short int w3 = 0;

    w3 = w1 ^ w2;
    printf("%d\n", w3);

    /* ^ OPERATOR
    10010011 = 147   
    00111101 = 61
    --------
    10101110 = 174
    */

    //Example
    /*What you normaly would do
        temp = w1;
        w1 = w2;
        w2 = temp;
    */
    //you can save memory by doing the bellow (no temp int)

    w1 ^= w2;
    w2 ^= w1;
    w1 ^= w2;
}

void OnesAndTwosComplement()
{
    signed int w1 = 3;
    signed int result = 0;

    result = ~(w1);
    printf("%d\n", result);

    /*  ONES COMPLEMENT
    0000 0011    = 154
    --------
    1111 1100    = 252
    */

    /*
    1111 1100       Get ones complement
    0000 0001       Add one in binary to it
    ---------
    1111 1101    = -3 (-3 is 2's complement of +3)
    */

   
}