#include <stdio.h>
#include <pthread.h>

void* hello_func(){
    printf("Hello, Thread!\n");
    return NULL;
}

int main(){
    pthread_t thread = 0;
    pthread_create(&thread, NULL, hello_func, NULL);
    /*
        1st argument: An integer used to identify the thread in the system
        2nd argument: Specify thread attributes or NULL for default vals
        3rd argument: Name of the function the thread will execute once created
        4th argument: Pass arguments to the function a cast to a void* is required or NULL if no argument
    */
    pthread_join(thread, NULL); //wait until thread is finished to exit main
    pthread_exit(NULL);         //it is also good practice but not required to run pthread_exit
}