#include <stdio.h>
#include <pthread.h>

void *print_message_func(void *ptr);

int main(void){
    pthread_t thread1 = 0, thread2 = 0;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1 = 0, iret2 = 0;

    iret1 = pthread_create(&thread1, NULL, print_message_func, (void*)message1);
    iret2 = pthread_create(&thread2, NULL, print_message_func, (void*)message2);

    //wait until threads are complete until main continues
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);
    pthread_exit(NULL);
    return 0;
}

void* print_message_func(void *ptr){
    char *message;
    message = (char*)ptr;
    printf("%s\n", message);
}