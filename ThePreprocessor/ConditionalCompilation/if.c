#include <stdio.h>

#define MYDEF 5
#define MYOTHERDEF 2

int main(){
    #if MYDEF == 5 && MYOTHERDEF == 2
        printf("Hello\n");
    #endif

    return 0;
}