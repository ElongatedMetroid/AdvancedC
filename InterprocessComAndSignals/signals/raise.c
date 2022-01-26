#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(){
    printf("Raising SIGSTOP\n");
    raise(SIGSTOP);
    printf("I am back\n\n");    //to access this line use "kill -s SIGCONT <process ID>" you can get the process ID by typing "ps"
    return 0;
}