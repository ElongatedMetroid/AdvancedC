#include <stdio.h>

#if __STDC_VERSION_!=201112L    //should fail if compiler used is an older standard and succeed when it uses C11
    #error Not C11
#endif

int main(){
    int *******************************************************i = 0;
    return 0;
}