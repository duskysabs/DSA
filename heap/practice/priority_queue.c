#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[50];
    int priority;
}Task;

typedef struct{
    Task *arr;
    int size;
    int capacity;
}prioQueue;

void swap(Task *a, Task *b){
    Task temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDownRecursive(prioQueue *q, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && q->arr[left].priority > q->arr[largest].priority){
        largest = left;
    }
    
    if(right < n && q->arr[right].priority > q->arr[largest].priority){
        largest = right;
    }
    
    if(largest!=i){
        Task temp = q->arr[i];
        q->arr[i] = q->arr[largest];
        q->arr[largest] = temp;
        heapifyDown(q, n, largest);
    }
}

void heapifyDownIterative(Task *arr, int n, int i) {
    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && q->arr[left].priority > q->arr[largest].priority) {
            largest = left;
        }
        
        if (right < n && q->arr[right].priority > q->arr[largest].priority) {
            largest = right;
        }
        
        if (largest == i) {
            break;  // Heap property satisfied
        }
        
        swap(&arr[i], &arr[largest]);
        i = largest;  // Move down to the child position
    }
}

void heapifyUpRecursive(Task *arr, int index) {
    if (index <= 0) {
        return;  // Base case: reached root
    }
    
    int parent = (index - 1) / 2;
    
    if (arr[index].priority > arr[parent].priority) {
        swap(&arr[index], &arr[parent]);
        heapifyUpRecursive(arr, parent);  // Recursive call
    }
}


void heapifyUpIterative(prioQueue *q, int index){
    while(index>0){
        int parent = (index-1) / 2;
        if(q->arr[index].priority > q->arr[parent].priority){
            swap(&q->arr[index], &q->arr[parent]);
            index = parent;
        } else {
        break;
        }
    }
}

void buildHeap(prioQueue *q){
    for(int i = q->size / 2 - 1; i>=0; i--){
        heapifyDown(q, q->size, i);
    }
}

void HeapSort(prioQueue *q){
    prioQueue tempQ;
    tempQ.arr = malloc(sizeof(Task) * q->size);
    tempQ.size = q->size;
    tempQ.capacity = q->capacity;
    memcpy(tempQ.arr, q->arr, sizeof(Task)*q->size);
    
    while(tempQ.size > 0){
        printf("%s\n", tempQ.arr[0].name);
        tempQ.arr[0] = tempQ.arr[tempQ.size - 1];
        tempQ.size--;
        heapifyDown(&tempQ, tempQ.size, 0);
    }
    
}

void insert(prioQueue *q){
    for(int i=0; i<q->capacity; i++){
        printf("Enter task name: ");
        scanf("%s", q->arr[i].name);
        printf("Enter task priority: ");
        scanf("%d", &q->arr[i].priority);
        q->size++;
        heapifyUp(q, i);
    } 
}



