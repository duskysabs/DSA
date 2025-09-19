#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;

Queue* initialize();
Node* createNode(int value);
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);
void displayMenu();


int main(){
    Queue *q = initialize();
    int data, choice;
    do{
        displayMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(q, data);
                printf("\n");
                break;
            case 2:
                data = dequeue(q);
                printf("data dequeued: %d\n\n", data);
                break;
            case 3:
                data = front(q);
                printf("data at front: %d\n\n", data);
                break;
            case 4:
                display(q);
                printf("\n\n");
        }
    }while(choice<5);
}

Queue* initialize(){
    Queue *q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

Node* createNode(int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = value;
    return newNode;
}

bool isFull(Queue *q){ return false; }
bool isEmpty(Queue *q){ return q->front == NULL; }

void enqueue(Queue *q, int value){
    Node* newNode = createNode(value);
    if(isEmpty(q)){
        q->rear = newNode;
        q->front = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty. ");
        return -1;
    }
    Node* temp = q->front;
    int tempData = temp->data;
    q->front = temp->next;
    free(temp);
    return tempData;
}

int front(Queue *q){ return (!isEmpty(q)) ? q->front->data : -1; }

// void display(Queue *q){
//     Node* trav = q->front;
//   while(trav!=NULL){
//       printf("%d ",->data);
//       trav = trav->next;
//   }
// }

void display(Queue *q){
    Queue *temp = initialize();
    while(q->front!=NULL){
        int data = dequeue(q);
        printf("%d ", data);
        enqueue(temp, data);
    }
    
    while(temp->front!=NULL){
        int data = dequeue(temp);
        enqueue(q, data);
    }
}

void displayMenu(){
    printf("1.enqueue\n2.dequeue\n3.front\n4.Display\n5.Exit\nEnter: ");
}

