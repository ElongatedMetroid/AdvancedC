#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *fp;
    int numWords = 1;
    int numChar = 0;
    char ch = '\0';

    if( argc == 2 ) {
        printf("The argument supplied is %s\n", argv[1]);

        fp = fopen(argv[1], "r");
        if(!fp){
            printf("Error in opening file!\n");
            exit(1);
        }

        ch = getc(fp);

        while(ch != EOF){
            if(ch == ' '||ch == '\n')
                ++numWords;
            else
                ++numChar;
        ch = getc(fp);
        }

        printf("The number of words in the file are: %i\n", numWords);
        printf("The number of characters in the file are: %i\n", numChar);

        fclose(fp);
    }
    else if( argc > 2 ) {
        printf("Too many arguments supplied!\n");
    }
    else {
        char str[255];

        for(int i = 0; (str[i] = getchar()) != EOF; ++i)

        numWords = 1;
        numChar = 0;
        for(int i = 0; i < strlen(str); ++i){
            if(str[i] == ' ')
                numWords++;
            else
                numChar++;
        }

        printf("The number of words in the file are: %i\n", numWords);
        printf("The number of characters in the file are: %i\n", numChar-=1);
    }

    return 0;
}