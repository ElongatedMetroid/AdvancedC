#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    FILE *origfp;
    FILE *newfp;
    char ch = '\0';

    origfp = fopen("lowercase.txt", "r+");
    if(!origfp){
        printf("Error eccoured in opening lowercase.txt\n");
        exit(1);
    }
    newfp = fopen("temp.txt", "w+");
    if(!newfp){
        printf("Error eccoured in opening temp.txt\n");
        exit(1);
    }

    while(ch != EOF){
        ch  = fgetc(origfp);
        if(isupper(ch))
            fputc(toupper(ch), newfp);
        else
            fputc(tolower(ch), newfp);
    }

    remove("lowercase.txt");

    rename("temp.txt", "uppercase.txt");

    fclose(origfp);
    fclose(newfp);
}