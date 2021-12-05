#include <stdio.h>

int main(void)
{
    unsigned int packedData; //32 bits on most systems
    //    f1 f2 f3
    // 000 0 0 0 00000000 000000000000000000
    // ^unused   ^type     ^index

    packedData = packedData | 7 << 18;  //sets the "type" to 7

    //Retreving that data is easy as shown bellow

    int n;

    n = (packedData >> 18) & 0xff;  //to ensure that n is between 0 and 255 you can & it with 0xff (255)

    printf("%i\n", n);

    return 0;
}