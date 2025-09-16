#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);
void displayMenu();

int main(){
    EPtr L = malloc(sizeof(Etype));
    initialize(L);
    int choice, data, position;
    do{
        displayMenu();
        scanf("%d", &choice);
            switch(choice){
            case 1:
                printf("Enter number: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertPos(L, data, position);
                printf("\n");
                break;
            case 2:
                printf("Enter a position: ");
                scanf("%d", &position);
                deletePos(L, position);
                printf("\n");
                break;
            case 3:
                printf("Enter number: ");
                scanf("%d", &data);
                position = locate(L, data);
                if(position!=-1){
                    printf("Data is found");
                }
                else{
                    printf("Data is not found");
                }
                printf("\n");
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                data = retrieve(L, position);
                if(data!=-1){
                    printf("%d was found in position %d", data, position);
                }
                else{
                    printf("position was out of bounds.");
                }
                printf("\n");
                break;
            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                insertSorted(L, data);
                printf("\n");
                break;
            case 6:
                display(L);
                printf("\n\n");
                break;
            }
    }while(choice!=7);
}

void initialize(EPtr L){
    L->count = 0;
    for(int i=0; i<MAX; i++){
        L->elem[i] = -1;
    }
}

void insertPos(EPtr L, int data, int position){
    if(position > L->count){
        printf("Enter a valid position.");
        return;
    }
    if(L->elem[position]!=-1){
        for(int i=L->count; i>position; i--){
            L->elem[i] = L->elem[i-1];
        }
        L->elem[position] = data;
        L->count++;
        return;
    }
    else{
        L->elem[position] = data;
        L->count++;
        return;
    }
}
void deletePos(EPtr L, int position){
    if(position > L->count){
        printf("Enter a valid position. ");
        return;
    }
    else{
        for(int i=position; i<L->count-1; i++){
            L->elem[i] = L->elem[i+1];
        }
        L->count--;
    }
}

int locate(EPtr L, int data){
    for(int i=0; i<L->count; i++){
        if(L->elem[i] == data){
            return data;
        }
    }
    return -1;
}

int retrieve(EPtr L, int position){
    if(position > L->count){
        return -1;
    }
    return L->elem[position];
    
}

void insertSorted(EPtr L, int data){
    if(L->count == MAX){
        printf("Array is now full.");
        return;
    }
    int i;
    for(i = L->count-1; i>0 && L->elem[i] > data; i--){
        L->elem[i+1] = L->elem[i];    
    }
    L->elem[i+1] = data;
    L->count++;
}

void display(EPtr L){
    for(int i=0; i<L->count; i++){
        printf("%d ", L->elem[i]);
    }
    printf("Count: %d", L->count);
}

void makeNULL(EPtr L){
    free(L);
}

void displayMenu(){
    printf("1. insert at position \n");
    printf("2. delete at position \n");
    printf("3. locate \n");
    printf("4. retrieve \n");
    printf("5. insert sorted \n");
    printf("6. display \n");
    printf("7. Exit\n");
    printf("Enter your choice:");
}
