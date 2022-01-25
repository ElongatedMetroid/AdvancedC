#include <stdio.h>
#include <stdlib.h>

#define INSERT 1
#define DELETE 2
#define DISPLAY 3
#define EXIT 4

#define MAX 50

void enqueue();
void dequeue();
void display();

int queue_array[MAX];
int rear = -1;
int front = -1;

int main(void){
    int choice;
    while(1){
        printf(
            "Press 1 to Insert element to queue\n"
            "Press 2 to Delete element from queue\n"
            "Press 3 to Display all elements of queue\n"
            "Press 4 to Exit\n"
            "Enter your choice : "
        );
        scanf("%d", &choice);
    
        switch(choice){
            case INSERT:
                enqueue();
                break;
            case DELETE:
                dequeue();
                break;
            case DISPLAY:
                display();
                break;
            case EXIT:
                exit(EXIT_SUCCESS);
            default:
                printf("Incorrect option!\n");
        }
    }
    
    return 0;
}

void enqueue(){
    int add_item = 0;

    if(rear == MAX - 1)
        printf("Queue Overflow!\n");
    else{
        if(front == -1)
            front = 0;
        
        printf("Insert the element in queue: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        return;
    }
    else{
        printf("Element deleted from the queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}

void display(){
    if(front == -1)
        printf("Queue is empty\n");
    else{
        for(int i = 0; i <= rear; i++ )
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}