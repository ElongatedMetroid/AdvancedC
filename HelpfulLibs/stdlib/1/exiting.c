#include <stdlib.h>
#include <stdio.h>

FILE *openFile(const char *file){
    FILE *inFile;

    if(!(inFile = fopen(file, "r"))){
        printf("Could Not Open The File!\n");
        exit(EXIT_FAILURE);                     //using defined exit conditions defined in stdlib.h
    }

    return inFile;
}

int main(void){

    return 0;                                   //no difference in exiting and returning from main
}