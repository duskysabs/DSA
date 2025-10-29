#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 11  
#define MAX_ITEMS 5
#define NAME_LEN 50
#define ITEM_LEN 50

typedef struct {
    char item[MAX_ITEMS][ITEM_LEN];
    int itemCount;
} CustomerOrder;

typedef struct {
    char name[NAME_LEN];
    CustomerOrder order;
} Customer;

typedef struct {
    int front, rear;
    Customer customers[MAX];
} Queue;

void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, Customer c);
Customer dequeue(Queue *q);
Customer front(Queue *q);
void printCustomer(Customer c);
void printQueue(Queue* q);

int main() {
    Queue q;
    initQueue(&q);   // initialize queue

    // Prepare 10 customers
    Customer customers[5] = {
        {"Alice",   { {{"Mango Yogurt"}, {"Original Yogurt"}}, 2 }},
        {"Bob",     { {{"Original Yogurt"}}, 1 }},
        {"Charlie", { {{"Chocolate Yogurt"}, {"Banana Yogurt"}, {"Mango Yogurt"}}, 3 }},
        {"Diana",   { {{"Mango Graham Yogurt"}}, 1 }},
        {"Evan",    { {{"Ube Yogurt"}, {"Avocado Yogurt"}}, 2 }},
    };

    enqueue(&q, customers[0]);
    enqueue(&q, customers[1]);
    enqueue(&q, customers[2]);
    enqueue(&q, customers[3]);
    enqueue(&q, customers[4]);
    
    printQueue(&q);
    customers[0] = dequeue(&q);
    customers[1] = dequeue(&q);
    printf("\nDequeuing customer %s", q.customers[0].name);
    printf("\nDequeuing customer %s\n\n", q.customers[1].name);
    printQueue(&q);
    /*
    - Enqueue all customers
    - Print the queue
    - Qequeue two customers
    - Print the updated queue
    */

    //Implement code here...


    return 0;
}

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = MAX - 1; 
}

int isEmpty(Queue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

int isFull(Queue *q) {
    return (q->front == (q->rear + 2) % MAX);
}

void enqueue(Queue *q, Customer c) {
    if(!isFull(q)){
        q->rear = (q->rear + 1) % MAX;
        q->customers[q->rear] = c;
    }
    else{
        printf("queue is full.");
    }
}

Customer dequeue(Queue *q) {
    if(!isEmpty(q)){
        int value = q->front;
        q->front = (q->front+1) % MAX;
        return q->customers[value];
    }
    else{
        printf("Queue is empty.");
        Customer dummy;
        strcpy(dummy.name, "N/A");
        dummy.order.itemCount = 0;
        return dummy;
    }
}

Customer front(Queue* q){
    return q->customers[q->front];
}

void printCustomer(Customer c) {
    printf("Customer: %-10s | Order Count: %d\n", c.name, c.order.itemCount);
    for (int i = 0; i < c.order.itemCount; i++) {
        printf("    - %s\n", c.order.item[i]);
    }
    printf("------------------------------------\n");
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    Queue temp;
    initQueue(&temp);

    printf("======= Current Queue =======\n\n");

    while (!isEmpty(q)) {
        Customer c = dequeue(q);
        printCustomer(c);
        enqueue(&temp, c);
    }

    while (!isEmpty(&temp)) {
        enqueue(q, dequeue(&temp));
    }
}