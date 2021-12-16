//fscanf provides the same operations as scanf but on a file
//int fscanf(FILE *fp, const char *format, [argument, ...])
//fscanf(myFile, "%i", &i)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(){
    FILE *fp = NULL;
    char buf[MAX];
    char words[MAX];

    if(!(fp = fopen("file.txt", "a+"))){
        fprintf(stderr, "Unable to open file!\n");
        exit(1);
    }

    //while(fscanf(fp, "%s", buf) != EOF)
    //    printf("%s ", buf);

    puts("\nEnter words to add to the file; press the #");
    puts("Key at the beginning of a line to terminate.");
    while((fscanf(stdin, "%40s", words) == 1)  && (words[0] != '#'))
        fprintf(fp, "%s\n", words);

    puts("File Contents:");
    rewind(fp);         //go back to beginning of file
    while(fscanf(fp, "%s", words) == 1)
        puts(words);

    fclose(fp);
    fp = NULL;

    return 0;
}