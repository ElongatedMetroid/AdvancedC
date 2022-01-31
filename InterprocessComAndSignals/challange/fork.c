#include <unistd.h>
#include <stdio.h>
//has weird output because of printf
int main(void){
    int f1 = fork();
    int f2 = fork();

    if(f1 > 0 && f2 > 0){
        printf("Parent\n");
        printf("\tMy ID is %d\n", getpid());
        printf("\tMy parentid is %d\n", getppid());
    }
    if(f1 == 0 && f2 > 0){
        printf("First Child\n");
        printf("\tMy ID is %d\n", getpid());
        printf("\tMy parentid is %d\n", getppid());
    }
    if(f1 > 0 && f2 == 0){
        printf("Second Child\n");
        printf("\tMy ID is %d\n", getpid());
        printf("\tMy parentid is %d\n", getppid());
    }
    else{
        printf("Third Child\n");
        printf("\tMy ID is %d\n", getpid());
        printf("\tMy parentid is %d\n", getppid());
    }

    return 0;
}