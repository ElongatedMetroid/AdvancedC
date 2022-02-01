#include <stdio.h>
#include <pthread.h>
#include <string.h>

void* hello_return(void *args){
    char *hello = strdup("Hello, World!\n");
    return (void*)hello;
}

int main(void){
    char *str;
    pthread_t thread = 0;

    pthread_create(&thread, NULL, hello_return, NULL);

    pthread_join(thread, (void**)&str);
    
    //pthread_exit(NULL); //cant have exit here because it will end the thread

    printf("%s", str);
    
    return 0;
}