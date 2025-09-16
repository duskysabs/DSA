#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
void displayMenu();

int main(){
    List L;
    int choice, data, position;
    L = initialize(L);
    do{
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
;       switch(choice){
            case 1:
                printf("Enter number: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                L = insertPos(L, data, position);
                printf("\n");
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &position);
                L = deletePos(L, position);
                printf("\n");
                break;
            case 3:
                printf("Enter what data you want to locate: ");
                scanf("%d", &data);
                position =locate(L, data);
                if(position!=-1){
                    printf("data has been found at index %d\n\n", position);
                }
                else{
                    printf("data has not been found.\n\n");
                }
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                L = insertSorted(L, data);
                printf("\n");
                break;
            case 5:
                display(L);
        }
    }while(choice<6);
}

void displayMenu(){
    printf("Enter your choices:\n");
    printf("1. insert at position \n");
    printf("2. delete at position \n");
    printf("3. locate \n");
    printf("4. insert sorted \n");
    printf("5. display \n");
    printf("6. Exit");
}

List initialize(List L){
    for(int i=0; i<MAX; i++){
        L.elem[i] = -1;
    }
    L.count = 0;
    return L;
}
List insertPos(List L, int data, int position){
    if(L.count == MAX){
        printf("Array has reached its limit.");
        return L;
    }
    if(position > L.count && MAX){
        printf("Enter valid position.\n");
        return L;
    }
    if(L.elem[position]!=-1){
        for(int i=L.count; i>position; i--){
            L.elem[i] = L.elem[i-1];
        }
        L.elem[position] = data;
        L.count++;
        return L;
    }
    else{
        L.elem[position] = data;
        L.count++;
        return L;
    }
    printf("\n");
}

List deletePos(List L, int position){
    if(position > L.count-1){
        printf("Enter valid position.\n\n");
        return L;
    }
    if(L.count == 0){
        printf("Nothing to delete.");
        return L;
    }
    for(int i=position; i<L.count-1; i++){
        L.elem[i] = L.elem[i+1];
    }
    L.count--;
    return L;
    printf("\n");
}

int locate(List L, int data){
    for(int i=0; i<L.count; i++){
        if(L.elem[i] == data){
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    int i;
    if(L.count == MAX){
        printf("Array has reached its limit.");
        return L;
    }
    for(i=L.count-1; i >= 0 && L.elem[i] > data; i--){
        L.elem[i+1] = L.elem[i];
    }
    L.elem[i+1] = data;
    L.count++;
    printf("\n");
    return L;
}

void display(List L){
    printf("\n");
    for(int i=0; i<L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\nCount: %d\n", L.count);
    printf("\n\n");
}