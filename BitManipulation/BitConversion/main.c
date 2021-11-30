#include <stdio.h>
#include <string.h>
#include <math.h>

long long int BinToDec(char *bin);

int main(void)
{
    char bin[255];

    scanf("%s", bin);
    printf("%lld\n", BinToDec(bin));
    return 0;
}

long long int BinToDec(char *bin)
{
    long long int dec = 0;
    size_t len = strlen(bin), cp_len = len-1;
  
    for(int n = 0; n < len; --cp_len) 
    {
        if (bin[n++] == '1')
            dec += (long long int) pow(2, (double) cp_len);
    }
    return dec;
}