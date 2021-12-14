#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fgetsExample();
void getlineExample();

int main(void){
    
    fgetsExample();
    getlineExample();

    return 0;
}

void fgetsExample(){
    char buf[255];
    int ch = '\0';
    char *p = NULL;

    if(fgets(buf, sizeof(buf), stdin)){
        p = strchr(buf, '\n');  //returns a pointers to the first occurence of \n
        if(p){  //if the \n is found add a \0 to the end
            *p = '\0';  
        }
        else{
            while(((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin));
        }
    }
}

void getlineExample(){
    char *buffer = NULL;
    size_t bufsize = 32;
    size_t characters;

    buffer = (char*)malloc(bufsize * sizeof(char));

    if(!buffer){
        exit(1);
    }

    printf("Type Something: ");
    characters = getline(&buffer, &bufsize, stdin);

    printf("%zu characters were read.\n", characters);  //uses %zu because of size_t
    printf("You typed: '%s'\n", buffer);
}