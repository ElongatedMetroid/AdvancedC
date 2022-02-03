#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREAD 10

pthread_mutex_t lockCount = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

void* thread_func(void *ptr){
    int *x = (int *)ptr;

    pthread_mutex_lock(&lockCount);

    count++;
    
    printf("Message Passed to me %d, Thread ID %ld, Modified The Counter To %d\n", *x, pthread_self(), count);
    printf("Message Passed to me %d, Thread ID %ld, Read The Counter %d\n", *x, pthread_self(), count);

    pthread_mutex_unlock(&lockCount);
}

int main(void){
    pthread_t threads[NUM_THREAD];

    for(int i = 0; i < NUM_THREAD; i++){
        if(pthread_create(&threads[i], NULL, thread_func, (void*)i) != 0){
            printf("Error Creating Thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    for(int i = 0; i < NUM_THREAD; i++)
        pthread_join(threads[i], NULL);

    pthread_exit(NULL);

    return EXIT_SUCCESS;
}