#include <stdio.h>
#include <string.h>
#include <math.h>

long long int BinToDec(char *bin);
//long long int DecToBin(char *dec);

int main(void)
{
    char bin[255];
    char dec[255];

    printf("Enter the Binary to be converted to decimal (unsigned)");
    scanf("%s", bin);
    printf("%lld\n", BinToDec(bin));
    //scanf("%s", dec);
    //printf("%lld\n", DecToBin(dec));
    return 0;
}

long long int BinToDec(char * bin)                                                                                                     /*EXAMPLE (using 00000001)*/
{
    long long int dec;                      //creates decimal variable it will later return
    const size_t inputLen = strlen(bin);    //creates are variable that saves the input length                                          8
    size_t editLen;                         //creates a variable that saves the input length, this one will be edited though    
    editLen = inputLen - 1;                 //this sets the editLen to be equal to one less than the input length                       7

    for(int i = 0; i < inputLen;)           //goes while i is less than inputLen
    {
        if(bin[i++] == '1')                 //if bin i+1 is equal to 1 do the following                                                 editLen - 7 = 0, 2^0 = 1 <---Answer                            
            dec += (long long int)pow(2, (long long int) editLen);  //dec equals 2 to the power of editLen                              2^7=128, 2^6=64, etc   
        --editLen;                          //subtracts 1 for edit len                                                                  
    }

    return dec;
}
