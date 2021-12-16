#include <stdio.h>
#include <stdlib.h>

int checkPrime(int number);

int main(){

    FILE *fp;
    int num = 0;

    if(!(fp = fopen("numbers.txt", "r"))){
        printf("Error ecoured while opening the file!\n");
        exit(1);
    }

    while(!feof(fp)){
        int m;

        fscanf(fp, "%500d", &num);

        if(num < 0){
            printf("Negative number found!: %d\n", num);
        }
        else if(checkPrime(num) == 0){
            printf("Prime number found!: %d\n", num);
        }

        if((num & 1) == 0)                                          //0000 0001
            printf("Even number found!: %d\n", num);                //0000 0010 = even number, no even number has 1 switched on
        else
            printf("Odd number found!: %d\n", num);

    }

    return 0;
}

int checkPrime(int number)
{
    int count = 0;
    for(int i=2; i<=number/2; i++)
    {
        if(number%i == 0)
        {
            count=1;
            break;
        }
    }
    if(number == 1) count = 1;
    return count;
}