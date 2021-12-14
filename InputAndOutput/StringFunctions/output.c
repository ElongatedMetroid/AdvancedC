#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void putsExample();
void fputsExample();

int main(){
    putsExample();
    fputsExample();
    return 0;
}

void putsExample(){
    char str[40];
    strcpy(str, "Hello World");
    puts(str);
}

void fputsExample(){
    FILE *fp = NULL;
    fp = fopen("file.txt", "w");

    if(!fp){
        exit(1);
    }

    fputs("Hello There, I hope this is a good example!", fp);

    fclose(fp);
}