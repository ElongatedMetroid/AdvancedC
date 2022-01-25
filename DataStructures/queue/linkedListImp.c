#include <stdio.h>
#include <stdlib.h>

struct QNode{
    int key;
    struct QNode* next;
};

struct Queue{
    struct QNode *front, *rear;
};

struct QNode* newNode(int k){
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int k){
    struct QNode *temp = newNode(k);

    //if queue is empty new node is front and rear
    if(q->rear == NULL){
        q->front = q->rear = temp;
        return;
    }

    //add the new node to the end of the queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

struct QNode* deQueue(struct Queue* q){
    if(q->front == NULL)    //if empty
        return NULL;

    //store previous front and move front one node ahead
    struct QNode* temp = q->front;  //store so we can return 
    q->front = q->front->next;

    //if front becomes NULL, then change rear to NULL
    if(q->front == NULL)
        q->rear = NULL;

    return temp;
}

int main(){
    struct Queue* q = createQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    deQueue(q);
    deQueue(q);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    struct QNode* n = deQueue(q);
    if(n != NULL)
        printf("Dequeued item is %d\n", n->key);

    return 0;
}