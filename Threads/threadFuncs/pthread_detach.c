#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* threadFunc(void *ptr){
    pthread_detach(pthread_self());
    sleep(1);
    printf("Thread Function\n");
    pthread_exit(NULL);
}

int main(){
    pthread_t thread = 0;
    int ret = pthread_create(&thread, NULL, threadFunc, NULL);

    if(ret != 0){
        perror("Thread creation error!\n");
        exit(EXIT_FAILURE);
    }

    printf("After thread created in main\n");
    pthread_exit(NULL);

}