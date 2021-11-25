#include <stdio.h>

extern void display();

int count;

int main(void)
{
    for(count = 0; count < 5; count++)
        display();
    
    return 0;
}