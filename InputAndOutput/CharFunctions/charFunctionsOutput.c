#include <stdio.h>

void putcExample();
void putcharExample();
void fputcExample();

int main(){
    putcExample();
    putcharExample();
    fputcExample();
    return 0;
}

void putcExample(){
    char ch = '\0';
    FILE *fp;

    if(fp = fopen("myFile", "a+")){
        ch = getc(fp);
        while(ch != EOF){
            putc(ch, fp);
            ch = getc(fp);
        }
    }
}

void putcharExample(){
    char str[] = "Hello World, \nHelp us poor newlines!\n";

    for(int i = 0; str[i] != '\0'; ++i){
        if(str[i] != '\n')                  //ignores newline
            putchar(str[i]);
    }

    putchar('\n');
}

void fputcExample(){
    FILE *fp;
    char c;

    fp = fopen("myFile", "w");
    
    if(fp){
        for(c = 'A'; c <= 'Z'; c++){    //prints the characters A to Z from the ASCII table
            fputc(c, fp);
            fputc(c, stdout);
        }

        fclose(fp);
        putchar('\n');
    }
}