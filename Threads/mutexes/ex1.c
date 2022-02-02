#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int globalVariable = 0;

void* do_process(){
    pthread_mutex_lock(&lock);
    int i = 0;
    globalVariable++;

    while(i < 5){
        printf("%d", globalVariable);
        sleep(1);
        i++;
    }

    puts("Done!");
    pthread_mutex_unlock(&lock);
}

int main(void){
    pthread_t t1 = 0, t2 = 0;

    if(pthread_mutex_init(&lock, NULL) != 0){
        puts("Mutex init failed!");
        return 1;
    }

    globalVariable = 0;

    if(pthread_create(&t1, NULL, do_process, NULL) != 0){
        puts("Thread Creation Error!\n");
        return 1;
    }

    if(pthread_create(&t2, NULL, do_process, NULL) != 0){
        puts("Thread Creation Error!\n");
        return 1;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_exit(NULL);

    return 0;
}