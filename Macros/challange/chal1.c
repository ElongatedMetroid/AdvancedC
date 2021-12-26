#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("__LINE__ = %d\n", __LINE__);
    printf("__FILE__ = %s\n", __FILE__);
    printf("__DATE__ = %s\n", __DATE__);
    printf("__TIME__ = %s\n", __TIME__);

    #if(__STDC__==1)
        printf("Implementation is ISO-conforming.\n");
    #else
        printf("Implementation is not ISO-conforming.\n");
    #endif
}