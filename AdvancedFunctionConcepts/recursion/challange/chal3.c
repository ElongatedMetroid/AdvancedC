#include <stdio.h>

char* reverseStr(char *str);

int main(){

    printf("%s\n", reverseStr("hello"));

    return 0;
}

char* reverseStr(char *str){
    static int i = 0;
    static char rev[100];

    if(*str){           //while the string is not NULL make the pointer move up until it hits \0 (NULL)
        reverseStr(str + 1);  //move pointer further down until it hits NULL
        rev[i++] = *str;    //set char array to the string
    }
        
    return rev;
}