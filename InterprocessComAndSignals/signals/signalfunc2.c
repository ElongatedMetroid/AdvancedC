#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void signalHandler(int signum);

int main(){
    int x = 0;  //hold random values

    signal(SIGINT, signalHandler);  //register signal handler
    srand(time(NULL));

    for(int i = 1; i <= 100; i++){
        x = 1 + rand() % 50;

        if(x == 25)
            raise(SIGINT);

        printf("%4d", i);

        if(i % 10 == 0)
            printf("\n");
    }

    return EXIT_SUCCESS;
}

void signalHandler(int signum){
    int response = 0;

    printf("%s%d%s\n%s", "\nInterrupt signal ( ", signum, " )", "Do you wish to continue (1 = yes or 2 = no)?");
    scanf("%d", &response);

    while(response != 1 && response != 2){
        printf("(1 = yes or 2 = no)?");
        scanf("%d", &response);
    }

    if(response == 1)
        signal(SIGINT, signalHandler);
    else
        exit(EXIT_SUCCESS);
}