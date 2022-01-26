#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void){
    alarm(5);

    // Need to catch SIGALRM or process terminates
    //signal(SIGALRM, alarmHandler);

    //terminates once 5 seconds have passed because of sleep alarm function
    for(int i = 1; i < 10; i++){
        printf("%d\n", i);
        sleep(1);
    }

    return 0;
}