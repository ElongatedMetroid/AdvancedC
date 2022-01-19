#include <stdio.h>
#include <stdlib.h>

void sign_off(void);
void too_bad(void);

int main(void){
    int n = 0;

    atexit(sign_off);       //call sign_off at exit
    puts("Enter an integer: ");

    if(scanf("%d", &n) != 1){
        puts("That is not an integer!!!!!!111!!!!111!11");
        atexit(too_bad);    //call too_bad at exit
        exit(EXIT_FAILURE);
    }

    return 0;
}

void sign_off(void){
    puts("in sign_off...");
}

void too_bad(void){
    puts("in too_bad...");
}