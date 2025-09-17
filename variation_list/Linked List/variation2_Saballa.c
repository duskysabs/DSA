#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List* initialize();
Node* createNode(int data);
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);
void displayMenu();


int main(){
    int choice, data, index;
    List *L = initialize();
    do{
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertFirst(L, data);
            break;
            case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertLast(L, data);
            break;
            case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter index: ");
            scanf("%d", &index);
            insertPos(L, data, index);
            break;
            case 4:
            deleteStart(L);
            printf("Deleted from the start.\n\n");
            break;
            case 5:
            deleteLast(L);
            printf("Deleted from the last.\n\n");
            break;
            case 6:
            printf("Enter index to delete: ");
            scanf("%d", &index);
            deletePos(L, index);
            printf("Deleted");
            break;
            case 7:
            printf("Enter index to retrieve: ");
            scanf("%d", &index);
            data = retrieve(L, index);
            if(data!=-1){
                printf("%d was retrived from index %d\n\n", data, index);
            }
            else{
                printf("data was not found. index out of bounds.\n\n");
            }
            break;
            case 8:
            printf("Enter data to locate: ");
            scanf("%d", &data);
            index = locate(L, data);
            if(index!=-1){
                printf("%d was found in index %d\n\n", data, index);
            }
            else{
                printf("data was not found. index out of bounds.\n\n");
            }
            break;
            case 9:
            display(L);
            break;
        }
    }while(choice<10);
}

List* initialize(){
    List *L = malloc(sizeof(List));
    L->head = NULL;
    L->count = 0;
    if(L->head == NULL && L->count == 0){
        printf("Memory allocated.\n");
        return L;
    }
    else{
        return NULL;
    }
}

Node* createNode(int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void empty(List *list){
    Node *trav = list->head;
    Node *temp;
    for(; trav!=NULL; trav = trav->next){
        temp = trav->next;
        trav = temp->next;
        free(temp);
    }
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data){
    Node *newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}
void insertLast(List *list, int data){
    Node *newNode = createNode(data);
    Node *trav = list->head;
    for(; trav->next!=NULL; trav = trav->next){
    }
    trav->next = newNode;
    list->count++;
}

void insertPos(List *list, int data, int index){
    Node *newNode = createNode(data);
    Node *trav = list->head;
    for(int i=0; i<index-1 && trav->next!=NULL; trav = trav->next, i++){
    }
    newNode->next = trav->next;
    trav->next = newNode;
    list->count++;
    
}
void deleteStart(List *list){
    Node* temp = list->head;
    list->head = temp->next;
    free(temp);
    list->count--;
}
void deleteLast(List *list){
    Node* temp = list->head;
    for(; temp->next->next!=NULL; temp = temp->next);
    free(temp->next);
    temp->next = NULL;
    list->count--;
}
void deletePos(List *list, int index){
    Node* trav = list->head;
    for(int i=0; i<index-1 && trav->next!=NULL; i++, trav = trav->next){
    }
    Node* temp = trav->next;
    trav->next = temp->next;
    free(temp);
    
}
int retrieve(List *list, int index){
    Node* trav = list->head;
    for(int i=0; i<index; i++){
        trav = trav->next;
    }
    return trav->data;
}

int locate(List *list, int data){
    Node *trav = list->head;
    int i = 0;
    while(trav!=NULL){
        if(trav->data == data){
            return i;
        }
        trav = trav->next;
        i++;
    }
    return -1;
}
void display(List *list){
    Node* trav = list->head;
    printf("Data: ");
    for(; trav!=NULL; trav = trav->next){
        printf("%d ", trav->data);
    }
    printf("\n\n");
}

void displayMenu(){
    printf("1. Insert First\n");
    printf("2. Insert Last\n");
    printf("3. Insert Pos\n");
    printf("4. Delete First\n");
    printf("5. Delete Last\n");
    printf("6. Delete Pos\n");
    printf("7. Retrieve\n");
    printf("8. Locate\n");
    printf("9. Display\n");
    printf("10. Exit\n");
}