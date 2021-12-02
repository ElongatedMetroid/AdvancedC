#include <stdio.h>

void LeftShifting();
void RightShifting();

int main(void)
{
    LeftShifting();
    RightShifting();
    return 0;
}

void LeftShifting()
{
    int w1 = 3;         // 0000 0000 0000 0000 0000 0000 0000 0011 = 3
    int result = 0;
                        // ^This bit is lost after the shift by 1
    result = w1 << 1;   // 0000 0000 0000 0000 0000 0000 0000 0110 = 6 

    printf("result (Left Shift): %d\n", result); //Prints result witch is 6 as shown above

}

void RightShifting()
{   //reccomended to use unsigned int because on some systems the new left most bits (you removed from shifting) are 1's not zeros
    unsigned int w1 = 4151832098;   // 1111 0111 0111 0111 1110 1110 0010 0010
    int result = 0;               

    result = w1 >> 1;               // 0111 1011 1011 1011 1111 0111 0001 0001

    printf("result (Right Shift): %d\n", result);

    w1 = 5;                         // 0000 ... 0101
    result = w1 >> 1;               // 0000 ... 0010

    printf("result (Right Shift): %d\n", result);
}