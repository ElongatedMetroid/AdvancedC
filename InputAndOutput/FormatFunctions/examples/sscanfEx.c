//read formatted data from a string rather than standard input or keyboard
//int sscanf(const char *str, const char * control_ string [arg_1, arg_2, ...])
//returns -1 if error

#include <stdio.h>
#include <stdlib.h>

int main(){

    char *str = "Mario Plumber 35";     
    char name[10], title[10];
    int age = 0, ret = 0;

    ret = sscanf(str, "%s %s %d", name, title, &age);   //seperates Mario, Plumber and 35 all into seperate variables

    printf("Name: %s\n", name);
    printf("Title: %s\n", title);
    printf("Age: %d\n", age);

    return 0;
}