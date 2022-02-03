#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t cond_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_condvar = PTHREAD_COND_INITIALIZER;

void* functionCount1();
void* functionCount2();
int count = 0;

#define NUM_THREADS 2
#define COUNT_DONE 10
#define COUNT_HALT1 3
#define COUNT_HALT2 6

int main(void){
    pthread_t thread1, thread2;

    if(pthread_create(&thread1, NULL, &functionCount1, NULL) != 0){
        puts("Could not create thread1!");
        return EXIT_FAILURE;
    }

    if(pthread_create(&thread2, NULL, &functionCount2, NULL) != 0){
        puts("Could not create thread2!");
        return EXIT_FAILURE;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return EXIT_SUCCESS;
}

void* functionCount1(){
    while(1){
        pthread_mutex_lock(&cond_mutex);

        while(count >= COUNT_HALT1 && count <= COUNT_HALT2)
            pthread_cond_wait(&cond_condvar, &cond_mutex);

        pthread_mutex_unlock(&cond_mutex);

        pthread_mutex_lock(&count_mutex);
        count++;
        printf("Counter value functionCount1: %d\n", count);
        pthread_mutex_unlock(&count_mutex);

        if(count >= COUNT_DONE) return NULL;
    }
}

void* functionCount2(){
    while(1){
        pthread_mutex_lock(&cond_mutex);

        if(count < COUNT_HALT1 || count > COUNT_HALT2)
            pthread_cond_signal(&cond_condvar);

        pthread_mutex_unlock(&cond_mutex);

        pthread_mutex_lock(&count_mutex);
        count++;
        printf("Counter value functionCount2: %d\n", count);
        pthread_mutex_unlock(&count_mutex);

        if(count >= COUNT_DONE) return NULL;
    }
}