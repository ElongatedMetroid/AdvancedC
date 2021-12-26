#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("%s (function) was called.\n", __func__);
    printf("This program was last compiled at %s", __DATE__);
    printf(" at %s\n", __TIME__);

    printf("\nYour are on the file %s, on line %d\n\n", __FILE__, __LINE__);

    #if(__STDC__==1)
        printf("Implementation is ISO-conforming.\n");
    #else
        printf("Implementation is not ISO-conforming.\n");
    #endif

    return 0;
}