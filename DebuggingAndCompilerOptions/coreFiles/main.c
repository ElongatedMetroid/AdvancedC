//gbd a.out core

#include <stdio.h>

int main(){
    char *str = "GfG";

    //Problem: trying to modify read only memory
    *(str+1) = 'n';
    return 0;
}