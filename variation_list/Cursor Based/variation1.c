#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int elem;
    int next;
}Cell, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
}VHeap;

typedef int List;

void initialize(VHeap *V); 
int allocSpace(VHeap *V);
void deallocSpace(VHeap *V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int *L, VHeap* V, int elem);
void insertPos(int* L, VHeap *V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);
void deleteAllOccurence(int* L, VHeap* V, int elem);
void display(int L, VHeap V);

int main(){
    VHeap VH;
    List L = -1; // empty list at start
    initialize(&VH);

    printf("=== Cursor-Based Linked List Test ===\n");

    insertFirst(&L, &VH, 10);
    insertLast(&L, &VH, 30);
    insertSorted(&L, &VH, 20);
    display(L, VH);
    insertLast(&L, &VH, 40);
    display(L, VH);
    insertLast(&L, &VH, 50);
    display(L, VH);
    insertSorted(&L, &VH, 15);
    display(L, VH);

    insertLast(&L, &VH, 5);
    display(L, VH);

    // printf("\nSorted Insert (15):\n");
    // insertSorted(&L, &VH, 15);
    // display(L, VH);

    insertPos(&L, &VH, 99);
    display(L, VH);

    printf("\nDelete element 20:\n");
    delete(&L, &VH, 20);
    display(L, VH);

    printf("\nDelete all occurrences of 10:\n");
    deleteAllOccurence(&L, &VH, 10);
    display(L, VH);

    return 0;
}

void initialize(VHeap *V){
    V->avail = 0;
    for(int i=0; i<MAX; i++){
        V->H[i].next = i+1;
        if(i == MAX-1){
            V->H[MAX-1].next = -1;
        }
    }
}

int allocSpace(VHeap *V){
    int ret = V->avail;
    if(V->avail != -1){
        V->avail = V->H[ret].next;
    }
    return ret;
}

void deallocSpace(VHeap *V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell!=-1){
        V->H[newCell].next = *L;
        V->H[newCell].elem = elem;
    }
    *L = newCell;
}

void insertLast(int *L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    int *trav = L;
    if(newCell!=-1){
        while(*trav!=-1){
            trav = &V->H[*trav].next;
        }
        V->H[newCell].next = -1;
        V->H[newCell].elem = elem;
        *trav = newCell;
    }
}

void insertSorted(int* L, VHeap* V, int elem){
    int *trav = L;
    int newCell = allocSpace(V);
    if(newCell!=-1){
        V->H[newCell].elem = elem;
        while(*trav!=-1  && V->H[*trav].elem < elem){
            trav = &V->H[*trav].next;
        }
        V->H[newCell].next = *trav;
        *trav = newCell; 
    }
}

void insertPos(int* L, VHeap *V, int elem){
    int index;
    int *trav = L;
    int newCell = allocSpace(V);

    if(newCell!=-1){
        printf("enter index: ");
        scanf("%d", &index);
        V->H[newCell].elem = elem;

        for(int i=0; *trav!=-1 && i<index-1; i++){
            trav = &V->H[*trav].next;
        }

        V->H[newCell].next = *trav;
        *trav = newCell;
    }

}

void delete(int* L, VHeap* V, int elem){
    int *trav = L;
    int temp;

    for(int i=0; *trav!=-1 && V->H[*trav].elem != elem; i++){
        trav = &V->H[*trav].next;
    }
    
    temp = *trav;
    *trav = V->H[*trav].next;
    deallocSpace(V, temp);
}

void deleteAllOccurence(int* L, VHeap* V, int elem){
    int *trav = L;
    int temp;

    while(*trav!=-1){
        if(V->H[*trav].elem == elem){
            temp = *trav;
            *trav = V->H[*trav].next;
            deallocSpace(V, temp);
        }
        trav = &V->H[*trav].next;
    }
}

void display(int L, VHeap V){
    printf("\n--- Display ---\n");
    printf("L = %d\n", L);
    printf("%-5s | %-5s | %5s\n","Index","Elem", "Next");
    
    int trav = L;
    int displayIndex = 0;
    
    while(trav != -1 && displayIndex < MAX){
        printf("%-5d | %-5d | %5d\n", displayIndex, V.H[displayIndex].elem, V.H[displayIndex].next);
        trav = V.H[trav].next;
        displayIndex++;
    }
    
    printf("List: ");
    trav = L;
    while(trav != -1){
        printf("%d", V.H[trav].elem);
        trav = V.H[trav].next;
        if(trav != -1) printf(" -> ");
    }
    printf(" -> NULL\n");
}
