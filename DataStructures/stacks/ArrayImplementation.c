#include <stdio.h>
#include <stdlib.h>

#define PUSH 1
#define POP 2
#define DISPLAY 3
#define EXIT 4

#define MAX 5

struct stack{
    int stk[MAX];
    int top;
};

typedef struct stack STACK;

STACK s;

void push(void);
int pop(void);
void display(void);

int main(void){
    int choice;
    int option = 1;
    s.top = -1;

    while(option){
        printf("Press 1 to PUSH\n"
               "Press 2 to POP\n"
               "Press 3 to DISPLAY\n"
               "Press 4 to EXIT\n"
        );

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice){
            case PUSH:
                push();
                break;
            case POP:
                pop();
                break;
            case DISPLAY:
                display();
                break;
            case EXIT:
                exit(EXIT_SUCCESS);
        }

        fflush(stdin);
        printf("Do you want to continue (0 or 1)?\n");
        scanf("%d", &option);
    }
}

void push(){
    int num = 0;
    if(s.top == (MAX - 1)){
        printf("Stack is Full!\n");
        return;
    }
    else{
        printf("Enter the element to be pushed\n");
        scanf("%d", &num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
}

int pop(){
    int num = 0;
    if(s.top == -1){    //-1 because that is what it is initilized to
        printf("Stack is Empty\n");
        return s.top;
    }
    else{
        num = s.stk[s.top];
        printf("Popped element is %d\n", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return(num);
}

void display(){
    if(s.top == -1){
        printf("Stack is empty\n");
        return;
    }
    else{
        printf("\nThe status of the stack is \n");
        for(int i = s.top; i >= 0; i--)
            printf("%i\n", s.stk[i]);
    }

    printf("\n");
}