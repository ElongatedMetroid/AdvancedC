#include <stdio.h>

struct packed_struct 
{
    unsigned int : 3;       //Padding
    unsigned int f1:1;
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int type:8;
    unsigned int index:18;
};

int main(void)
{
    struct packed_struct packed_data;

    packed_data.type = 7;

    unsigned int bit = packed_data.type;

    unsigned int i = packed_data.index / 5+1;

    packed_data.f2 = 1;
    if(packed_data.f2)  //==true
        printf("flag 2 is ON\n");

    return 0;
}