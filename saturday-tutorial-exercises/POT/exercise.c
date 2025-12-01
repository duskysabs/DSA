#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

typedef struct {
	int patient_id;
	int priority_num;
	String patient_name;
	String reason;
} PatientPriorityInfo;

typedef struct {
	PatientPriorityInfo patients[32];
	int last;
} HEAP;

void swap(PatientPriorityInfo* a, PatientPriorityInfo* b){
    PatientPriorityInfo temp = *a;
    *a = *b;
    *b = temp;
    
}

void heapifyUp(HEAP* heap, int i){
    if(i<=0){
        return;
    }
    int parent = (i-1)/2;
    if(heap->patients[i].priority_num > heap->patients[parent].priority_num){
        swap(&heap->patients[i], &heap->patients[parent]);
        heapifyUp(heap, parent);
    }
}

//exercise 1
void insertPatient(HEAP *heap, PatientPriorityInfo patient){
	heap->patients[heap->last] = patient;
	heapifyUp(heap, heap->last);
	heap->last++;
}

void heapifyDown(HEAP *heap, int n, int i){
    int largest = i;
    int left = i*2+1;
    int right = i*2+2;
    
    if(left < n && heap->patients[left].priority_num > heap->patients[largest].priority_num){
        largest = left;
    }
    if(right < n && heap->patients[right].priority_num > heap->patients[largest].priority_num){
        largest = right;
    }
    
    if(largest!=i){
        swap(&heap->patients[i], &heap->patients[largest]);
        heapifyDown(heap, n, largest);
    }
}

//exercise 2
void deleteFirst(HEAP *heap){
    if(heap->last == 0) return;
    heap->patients[0] = heap->patients[heap->last-1];
    heapifyDown(heap, --heap->last, 0);
}




