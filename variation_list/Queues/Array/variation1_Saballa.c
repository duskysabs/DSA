#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int count;
}List;

typedef struct{
    List list;
    int front;
    int rear;
}Queue;

Queue* initialize();
bool isFull(Queue *q);
bool isEmpty(Queue *q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);
void traverse(Queue* q);
void displayMenu();


int main(){
    Queue *q = initialize();
    int choice, data;
    do{ 
        displayMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                printf("%d is what is found in front.\n", data = front(q));
                break;
            case 4:
                display(q);
                break;;
        }
    }while(choice<5);
}

Queue* initialize(){
    Queue *q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->list.count = 0;
    return q;
}

bool isFull(Queue *q){ return q->list.count == MAX; }
bool isEmpty(Queue *q){ return q->list.count == 0; }

void enqueue(Queue *q, int value){
    List *L = &q->list;
    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    }
    if(!isFull(q)){
    L->items[q->rear] = value;
    q->rear = (q->rear + 1) % MAX;
    L->count++;
    }
}

int dequeue(Queue *q){
    List *L = &q->list;
    if(!isEmpty(q)){
        L->count--;
        int value = L->items[q->front];
        q->front = (q->front + 1) % MAX;
        return value;
    }
}

int front(Queue *q){
    List *L = &q->list;
    return L->items[q->front];
}



void display(Queue* q){
    List *L = &q->list;
    int j = q->front;
    for(int i=0; i<L->count; i++){
        printf("%d ", L->items[j]);
        j = (j+1)%MAX;
    }
    printf("Count: %d\n", L->count);
}

void displayMenu(){
    printf("1.Enqueue\n2.Dequeue\n3.Front\n4.Display\nChoice: ");
}