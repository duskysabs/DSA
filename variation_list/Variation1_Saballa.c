#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
   int list[MAX];
   int count;
}numList;

numList initialize(numList);
numList insertFirst(numList, int);
numList insertLast(numList , int);
numList insertPos(numList, int, int);
numList insertAt(numList , int, int);
void display(numList);


int main(){
    numList L;
    L = initialize(L);
    L = insertPos(L, 3, 5);
    L = insertSort(L, 3)
    // L =  insertFirst(L, 5);
    // L =  insertFirst(L, 6);
    // // L =  insertFirst(L, 7);
    display(L);
    // L = insertLast(L, 10);
}

void display(numList L){
    for(int i=0; i<MAX; i++){
        printf("%d ", L.list[i]);
    }
    printf("\nCount: %d", L.count);
}

numList initialize(numList L){
    int i;
    for(i=0; i<MAX; i++){
        L.list[i] = -1;    
    }
    L.count = 0;
    
    return L;
}

numList insertPos(numList L, int value, int pos){
    if(L.list[pos] != -1){
        L.list[pos] = value;
    }
    else{
        L.list[pos] = value;
        L.count++;
    }
    return L;
}

numList insertSorted(numList L, int value){
    int i, j;
    int key = 0;
    
    for(i=0; i<MAX && L.list[i]!=-1; i++){
        for(j=0; j<L.count && L.list[j]!=-1; j++){
            if(value < L.list[i]){
                key = L.list[i];
                L.list[i] = value;
                L.list[i+1]
            }
        }
    }
}


numList insertFirst(numList L, int value){
    int i = L.count;
    if(L.list[0] == -1){
        L.list[0] = value;
        L.count++;
        return L;
    }
    else{
    for(;i!=0; --i){
        L.list[i] = L.list[i-1];
    }
    L.list[0] = value;
    L.count++;
    return L;
    }
}

numList insertLast(numList L, int value){
    L.list[L.count++] = value;
    return L;
}
