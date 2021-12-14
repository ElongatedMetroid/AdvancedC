#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXBUF 255

int main(int argc, char *argv[]){
    if(argc == 3){
        FILE *fp;
        char buf[MAXBUF];
        char ch = '\0';
        int matchAmount = 0;

        ch = argv[1][0];

        if(!(fp = fopen(argv[2], "r+"))){
            printf("Error occured while opening the file!\n");
            ferror(fp);
            exit(EXIT_FAILURE);
        }

        while(fgets(buf, MAXBUF, fp)){
            if(strchr(buf, ch) != NULL){
                fputs(buf, stdout);
                ++matchAmount;
            }
        }

        if(matchAmount == 0){
            printf("No Matches Found!\n");
            exit(EXIT_SUCCESS);
        }

        fclose(fp);
        fp == NULL;
        return EXIT_SUCCESS;
    }
    else{
        printf("Inncorrect argument count!\n");
        exit(1);
    }
    return 0;
}