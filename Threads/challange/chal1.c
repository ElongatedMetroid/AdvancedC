#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREAD 10

int count = 0;

//as we can see this code is NOT thread safe!
void* thread_func(void *ptr){
    int *x = (int *)ptr;

    count++;
    
    printf("Message Passed to me %d, Thread ID %ld, Modified The Counter To %d\n", *x, pthread_self(), count);
    printf("Message Passed to me %d, Thread ID %ld, Read The Counter %d\n", *x, pthread_self(), count);
}

int main(void){
    pthread_t threads[NUM_THREAD];

    for(int i = 0; i < NUM_THREAD; i++){
        if(pthread_create(&threads[i], NULL, thread_func, (void*)"Hello World!") != 0){
            printf("Error Creating Thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    for(int i = 0; i < NUM_THREAD; i++)
        pthread_join(threads[i], NULL);

    pthread_exit(NULL);

    return EXIT_SUCCESS;
}