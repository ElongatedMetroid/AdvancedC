#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_attr_t attr;

void* getstacksize(void *threadid){
    long tid = 0;
    size_t mystacksize = 0;

    tid = (long)threadid;
    pthread_attr_getstacksize(&attr, &mystacksize);

    printf("Thread %ld: stacksize = %li bytes\n", tid, mystacksize);

    pthread_exit(NULL);
}

int main(void){
    pthread_t thread = 0;
    size_t stacksize = 0;
    pthread_t myID;
    long t = 5;

    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &stacksize);
    printf("Default stack size = %li\n", stacksize);
    stacksize = 9000000;    //set stack size to 9MB
    printf("Amount of stack needed per thread = %li\n", stacksize);
    pthread_attr_setstacksize(&attr, stacksize);

    printf("Creating thread with stack size = %li bytes\n", stacksize);

    myID = pthread_create(&thread, &attr, getstacksize, (void*)t);

    if(myID){
        printf("ERROR: could not create thread!\n");
        exit(EXIT_FAILURE);
    }

    pthread_exit(NULL);

    return 0;
}