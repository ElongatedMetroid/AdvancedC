#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *fp;
    int numWords = 0;
    int numChar = 0;

    if( argc == 2 ) {
        printf("The argument supplied is %s\n", argv[1]);

        fp = fopen(argv[1], "r");
        if(!fp){
            printf("Error in opening file!\n");
            exit(1);
        }

        for(numWords = 0; (fgetc(fp) != EOF);){
            if(fgetc(fp) == ' ')
                ++numWords;
        }

        printf("The number of words in the file are: %i\n", numWords+=1);
        
        fseek(fp, 0, SEEK_SET);

        printf("The number of characters in the file are: %i\n", numChar);

        fclose(fp);
    }
    else if( argc > 2 ) {
        printf("Too many arguments supplied!\n");
    }
    else {
        char str[255];

        for(int i = 0; (str[i] = getchar()) != EOF; ++i)

        numWords = 0;
        numChar = 0;
        for(int i = 0; i < strlen(str); ++i){
            if(str[i] == ' ')
                numWords++;
        }
        for(numChar = 0; numChar < strlen(str); numChar++);

        printf("The number of words in the file are: %i\n", numWords);
        printf("The number of characters in the file are: %i\n", numChar-=1);
    }

    return 0;
}