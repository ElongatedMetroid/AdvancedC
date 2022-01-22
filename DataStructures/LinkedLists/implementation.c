#include <stdio.h>
#include <stdlib.h>

//choice defines
#define INSERT 1
#define INSERT_END 2
#define INSERT_BEG 3
#define DEL 4
#define DEL_BEG 5
#define EXIT 6

typedef struct node{
    char data;
    struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr;

void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertAtBeginning(ListNodePtr *head, char value);
char delete(ListNodePtr *head, char value);
char deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

int main(void){
    ListNodePtr head = NULL;    //initially there are no nodes
    int choice = 0;             //users choice
    char item = '\0';           //char entered by user

    printf("Enter your choice:\n"
        "\t1 to insert an element into the list in alphabetical order.\n"
        "\t2 to insert an element at the end of the list.\n"
        "\t3 to insert an element at the beginning of the list.\n"
        "\t4 to delete an element from the list.\n"
        "\t5 to delete an element from the begining of the list.\n"
        "\t6 to end.\n"
    );

    printf(":: ");
    scanf("%d", &choice);

    while(choice != EXIT){
        switch (choice)
        {
            case INSERT:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insert(&head, item);                //insert item in list
                printList(head);
                break;

            case INSERT_END:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insertAtEnd(&head, item);           //insert item in list
                printList(head);
                break;

            case INSERT_BEG:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insertAtBeginning(&head, item);     //insert item in list
                printList(head);
                break;

            case DEL:
                if(!isEmpty(head)){
                    printf("Enter character to be deleted: ");
                    scanf("\n%c", &item);

                    //if character is found remove it
                    if(delete(&head, item)){    //remove item
                        printf("%c deleted.\n", item);
                        printList(head);
                    }
                    else
                        printf("%c not found.\n\n", item);
                }
                else
                    printf("List is empty.\n\n");
                break;

            case DEL_BEG:
                if(!isEmpty(head)){
                    printf("Enter character to be deleted: ");
                    deleteAtBeginning(&head);
                    printf("%c deleted.\n", item);
                    printList(head);
                }
                else
                    printf("List is empty");
                break;

            default:
                printf("Invalid choice.\n\n");

                //display menu
                printf("Enter your choice:\n"
                    "\t1 to insert an element into the list in alphabetical order.\n"
                    "\t2 to insert an element at the end of the list.\n"
                    "\t3 to insert an element at the beginning of the list.\n"
                    "\t4 to delete an element from the list.\n"
                    "\t5 to delete an element from the begining of the list.\n"
                    "\t6 to end.\n"
                );
                break;
        }
        printf("? ");
        choice = '\0';  //just to be safe
        scanf("%d", &choice);
    }

    printf("End of run.\n");

    return EXIT_SUCCESS;
}

void insert(ListNodePtr *head, char value){
    ListNodePtr newPtr;     //pointer to new node
    ListNodePtr prevPtr;    //pointer to prev node in list
    ListNodePtr currPtr;    //pointer to current node in list

    newPtr = malloc(sizeof(node_t));    //create node

    if(newPtr != NULL){
        newPtr->data = value;   //place value in node
        newPtr->nextPtr = NULL; //node does not link to another node

        prevPtr = NULL;
        currPtr = *head;

        while(currPtr != NULL && value > currPtr->data){    // ...value > curPtr->data... sort in alphabetical order 
            prevPtr = currPtr;          //send currPtr back
            currPtr = currPtr->nextPtr; //set currPtr to the next ptr since it was send back 
        }

        //insert new node at beginning of list if can
        if(prevPtr == NULL){
            newPtr->nextPtr = *head;
            *head = newPtr;
        }
        else{ //insert new node between prevPtr and currPtr
            prevPtr->nextPtr = newPtr;
            newPtr->nextPtr = currPtr;
        }
    }
    else    //malloc failed
        printf("%c not inserted. No memory available.\n", value);
}

void insertAtEnd(ListNodePtr *head, char value){
    ListNodePtr current = *head;

    if(current != NULL){                //if list is not empty
        while(current->nextPtr != NULL)
            current = current->nextPtr; //move current right twords end of list

        //When at end of list...
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = value;
        current->nextPtr->nextPtr = NULL;
    }
    else{   //if head is NULL
        current = malloc(sizeof(node_t));
        current->data = value;
        current->nextPtr = NULL;
        *head = current;
    }
}

void insertAtBeginning(ListNodePtr *head, char value){
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->nextPtr = *head;  //swap places with head (start)
    *head = new_node;
}

char delete(ListNodePtr *head, char value){
    ListNodePtr tempPtr;    //temp node ptr
    ListNodePtr prevPtr;    //pointer to prev node in list
    ListNodePtr currPtr;    //pointer to current node in list

    //delete first node
    if(value == (*head)->data){     //if value is equal to head nodes data
        tempPtr = *head;            //hold onto node being removed
        *head = (*head)->nextPtr;   //set head to the value of the next pointer
        free(tempPtr);              //free tempPtr
        return value;
    }
    else{
        prevPtr = *head;
        currPtr = (*head)->nextPtr;

        //loop to find correct location in list
        while(currPtr != NULL && currPtr->data != value){
            prevPtr = currPtr;          //move currPtr closer to front
            currPtr = currPtr->nextPtr; //move currPtr right (away from front)
        }
        if(currPtr != NULL){
            tempPtr = currPtr;
            prevPtr->nextPtr = currPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }

    return '\0';
}

char deleteAtBeginning(ListNodePtr *head){
    ListNodePtr tempPtr = NULL;     //temp node pointer

    if(head == NULL)
        return '\0';                //return NULL if head is empty
    else{
        tempPtr = *head;            //hold onto node being deleted
        *head = (*head)->nextPtr;   //de-thread the node
        free(tempPtr);              //free de-threaded node
    }
}

int isEmpty(ListNodePtr head){
    return head == NULL;
}

void printList(ListNodePtr currentPtr){
    if(currentPtr  == NULL)
        printf("List is empty.\n\n");
    else{
        printf("The list is:\n");

        while(currentPtr != NULL){
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
}