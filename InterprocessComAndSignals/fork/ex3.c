#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COUNT 10

void childProcess(void);
void parentProcess(void);

int main(){
    pid_t pid;

    pid = fork();

    if(pid == 0)
        childProcess();
    else if(pid > 0)
        parentProcess();
    else{
        printf("fork() failed!\n");
        return 1;
    }

    return 0;
}

void childProcess(void){
    for(int i = 1; i <= MAX_COUNT; i++)
        printf("\tThis line is from child, value %d\n", i);

    printf("\t*** Child Process is done ***\n");
}

void parentProcess(void){
    for(int i = 0; i <= MAX_COUNT; i++)
        printf("This line is from parent, value %d\n", i);

    printf("*** Parent is done ***\n");
}