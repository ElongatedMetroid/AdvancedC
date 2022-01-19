#include <stdio.h>
#include <string.h>

int main(void){
    char *p1 = "Nate";
    char *p2 = NULL;

    p2 = strdup(p1);
    printf("Duplicated string is : %s\n", p2);

    /****************************************/

    char source[] = "Nate";

    /*
        5 bytes of source are copied to a new memory
        allocated dynamically and pinter to copied
        memory is returned.
    */

   char * target = strndup(source, 5);

   printf("%s\n", target);

    return 0;
}