#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10
#define EMPTY -1
#define NOTFOUND -100

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main() {
    List myList;
    myList = initialize(myList);

    // Insert elements
    myList = insertPos(myList, 10, 0);
    myList = insertPos(myList, 20, 1);
    myList = insertPos(myList, 15, 1); 
    display(myList);

    // Insert sorted
    myList = insertSorted(myList, 12);
    myList = insertSorted(myList, 25);
    display(myList);

    // Delete element
    myList = deletePos(myList, 2);
    display(myList);

    // Locate
    int idx = locate(myList, 20);
    if(idx == NOTFOUND) printf("20 not found\n");

    free(myList.elemPtr);
    return 0;
}

List initialize(List L){
    L.elemPtr = malloc(sizeof(int)*LENGTH);
    for(int i=0; i<LENGTH; i++){
        L.elemPtr[i] = EMPTY;
    }
    L.count = 0;
    L.max = LENGTH;
    return L;
}

List insertPos(List L, int data, int position){
    if(L.count == L.max){
        L = resize(L);
    }
    for(int i = L.count; i>position; i--){
        L.elemPtr[i] = L.elemPtr[i-1];
    }
    L.elemPtr[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if(position >= L.count || position < 0){
        printf("Enter valid position.\n");
        return L;
    }
    
    for(int i=position; i<L.count; i++){
        L.elemPtr[i] = L.elemPtr[i+1];
    }
    L.count--;
    return L;
}

int locate(List L, int data){
    for(int i=0; i<L.count; i++){
        if(L.elemPtr[i] == data){
            printf("Data has been found at index %d.\n", i);
            return i;
        }
    }
    return NOTFOUND;
}

List insertSorted(List L, int data) {
    if(L.count == L.max) {
        L = resize(L); 
    }
    int i = 0;
    while(i < L.count && L.elemPtr[i] < data) {
        i++;
    }
    for(int j = L.count; j > i; j--) {
        L.elemPtr[j] = L.elemPtr[j-1];
    }
    L.elemPtr[i] = data;
    L.count++;
    return L;
}

void display(List L){
    for(int i=0; i<L.max; i++){
        printf("%d ", L.elemPtr[i]);
    }
    printf("Count: %d\n", L.count);
}

List resize(List L){
    int *temp = realloc(L.elemPtr, sizeof(int)*(L.max*2));
    if(temp!=NULL){
    L.elemPtr = temp;
    for(int i=L.max; i<L.max*2; i++){
        L.elemPtr[i] = EMPTY;
    }
    L.max = L.max *2;
    return L;
    }
    else{
        printf("realloc failed.");
        return L;
    }
}