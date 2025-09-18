#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;\
    int max;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);
void displayMenu();

int main(){
    List L = initialize(L);
    int choice, data, position;
    do{
        displayMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                L = insertPos(L, data, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                L = deletePos(L, position);
                break;
            case 3:
                printf("Enter data to locate: ");
                scanf("%d", &data);
                position = locate(L, data);
                (position != -1) ? printf("%d found in index %d\n", data, position) :  printf("data was not found.\n");
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                L = insertSorted(L, data);
                break;
            case 5:
                display(L);
                break;
            case 6:
                L = resize(L);
                break;
        }
    }while(choice<7);
}

// typedef struct{
//     int *elemPtr;
//     int count;\
//     int max;
// }List;

List initialize(List L){
    L.elemPtr = malloc(sizeof(int)*LENGTH);
    for(int i=0; i<LENGTH; i++){
        L.elemPtr[i] = -1;
    }
    L.count = 0;
    L.max = LENGTH;
    return L;
}

List insertPos(List L, int data, int position){
    if(position > L.count){
        printf("Position out of bounds. \n");
        return L;
    }
    if(L.elemPtr[position]!=-1){
        for(int i=L.count-1; i>=position; i--){
            L.elemPtr[i+1] = L.elemPtr[i];
        }
        L.elemPtr[position] = data;
    }
    else{
        L.elemPtr[position] = data;
    }
    L.count++;
    return L;
}
List deletePos(List L, int position){
    if(position > L.count){
        printf("Position out of bounds. \n");
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
            return data;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    int i=L.count-1;
    if(L.count == LENGTH){
        L = resize(L);
    }
    for(; L.elemPtr[i]>data; i--){
        L.elemPtr[i+1] = L.elemPtr[i];
    }
    L.elemPtr[i+1] = data;
    L.count++;
    return L;
}

void display(List L){
    printf("data: ");
    for(int i=0; i<L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }
    printf("\nCount: %d\n\n", L.count);
}

List resize(List L){
    int max = L.max*2;
    int *newBlock = malloc(sizeof(int)*max);
    for(int i=0; i<max; i++){
        newBlock[i] = -1;
    }
    for(int i=0; i<L.count; i++){
        newBlock[i] = L.elemPtr[i];
    }
    
    free(L.elemPtr);
    L.elemPtr = newBlock;
    L.max = max;
    return L;
}

void displayMenu(){
    printf("1. Insert Pos\n");
    printf("2. Delete Pos\n");
    printf("3. Locate\n");
    printf("4. insert Sorted\n");
    printf("5. display\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}