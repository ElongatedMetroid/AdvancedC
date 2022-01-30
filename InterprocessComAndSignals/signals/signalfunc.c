#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler_divideByZero(int signum);

int main(){
    int result = 0;
    int v1 = 0, v2 = 0;
    void (*sigHandlerReturn)(int);

    sigHandlerReturn = signal(SIGFPE, handler_divideByZero);

    if(sigHandlerReturn == SIG_ERR){
        perror("Signal Error: ");
        return EXIT_FAILURE;
    }

    v1 = 121;
    v2 = 0;
    result = v1/v2;
    printf("Result of Divide by Zero is %d\n", result);

    return EXIT_SUCCESS;
}

void handler_divideByZero(int signum){
    if(signum == SIGFPE){
        printf("Received SIGFPE, Divied by Zero Exception!\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Received %d Signal\n", signum);
}