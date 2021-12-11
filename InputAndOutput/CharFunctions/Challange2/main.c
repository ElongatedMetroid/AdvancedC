#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    FILE *fp;
    char buf[255];
    char fileLocation[255];

    printf("Enter the file name or location you want to read from and to.\n");
    scanf("%s", fileLocation);

    fp = fopen(fileLocation, "r+");
    if(!fp){
        printf("Error in opening the file!\n");
        exit(1);
    }

    for(int i = 0; (buf[i] = fgetc(fp)) != EOF; i++);

    fclose(fp);

    for(int i = 0; buf[i] != '\0'; i++){
        toupper(buf[i]);
    }

    fp = fopen(fileLocation, "w");
    if(!fp){
        printf("Error in opening the file!\n");
        exit(1);
    }
    
    for(int i = 0; buf[i] != '\0'; i++){
        fputc(buf[i], fp);
    }
}