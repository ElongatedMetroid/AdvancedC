//fprintf is printf but on a file
//int fprintf(FILE *stream, const char *format, ...)
//fprintf(outFile, "Hello, person!")

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = NULL;
    char buf[100];

    if(!(fp = fopen("file.txt", "w+"))){
        fprintf(stderr, "Cannot open the file file.txt!\n");
        exit(1);
    }

    for(int i = 0; i < 10; ++i)
        fprintf(fp, "The loop counter is equal to %d\n", i+1);

    fclose(fp);
    fp = NULL;

    return 0;
}