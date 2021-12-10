#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ReadFile();
int ungetChar();
void ReadStdin();

int main(){
    ReadFile();
    ungetChar();
    ReadStdin();

    return 0;
}

int ReadFile(){
    char c = '\0';
    FILE *fp;

    fp = fopen("myFile", "r+");

    if(!fp){
        printf("Couble not open file myFile\n");
        exit(1);
    }

    printf("Reading the file myFile\n");

    while(1){
        c = fgetc(fp);

        if(c == EOF)
            break;

        printf("%c", c);
    }
}

int ungetChar(){            //if you enter "     i" it prints "i"
    char ch = 0;
    while(isspace(ch = (char)getchar()));   //Read as long as there are spaces
        ungetc(ch, stdin);                  //put back the nonspace character

    printf("char is %c\n", getchar());
}

void ReadStdin(){
    printf("\n\nEnter a char\n\n");
    char ch = '\0';

    printf("%c\n", getchar());  //always gets from stdin

    ch = getc(stdin);           //getc can read from files aswell
    printf("read in character %c\n", ch);
}