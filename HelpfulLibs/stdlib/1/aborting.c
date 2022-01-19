#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *fp = NULL;

    fp = fopen("file.txt", "r");

    if(!fp){
        printf("FILE NOT FOUND. Aborting...\n");
        abort();
    }

    printf("Going to close the file...\n");
    fclose(fp);

    return 0;
}