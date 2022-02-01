#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* myFunc(void *ptr){
    printf("Hello World!\n");
    pthread_cancel(pthread_self()); //sends cancelisation request to the thread
    return NULL;
}

int main(void){
    pthread_t thread = 0;
    pthread_create(&thread, NULL, myFunc, NULL);
    pthread_join(thread, NULL);

    return 0;
}