#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void* thread_function(void*);
pthread_mutex_t mutexLoc = PTHREAD_MUTEX_INITIALIZER;

//resource we will provide locks on
int counter = 0;

int main(void){
    pthread_t thread_id[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++){
        if(pthread_create(&thread_id[i], NULL, thread_function, NULL) != 0){
            printf("Error in creating thread %d\n", i);
            return 1;
        }
    }

    for(int i = 0; i < NUM_THREADS; i++)
        pthread_join(thread_id[i], NULL);

    printf("Final counter value: %d\n", counter);

    return 0;
}

void* thread_function(void *ptr){
    printf("Thread number %ld\n", pthread_self());
    pthread_mutex_lock(&mutexLoc);      //lock mutex
    counter++;
    pthread_mutex_unlock(&mutexLoc);    //unlock
}