#include <stdio.h>

//gcc -D DATADIR=/usr/home
//gcc -D UNIX=1

int main(){

    #ifdef UNIX
        #define DATADIR "/uxn1/data"
        printf("Your on unix\n");
    #else
        #define DATADIR "\usr\data"
        printf("Your on something else\n");
    #endif

}