#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

Stack* initialize();
Node* createNode(int value);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void display(Stack *s);
void displayMenu();

int main(){
    Stack *s = initialize();
    int data, choice;
    do{
        displayMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(s, data);
                printf("\n");
                break;
            case 2:
                data = pop(s);
                printf("data popped: %d\n\n", data);
                break;
            case 3:
                data = peek(s);
                printf("data at top: %d\n\n", data);
                break;
            case 4:
                display(s);
                printf("\n\n");
        }
    }while(choice<5);
}

Stack* initialize(){
    Stack* s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isFull(Stack *s){
    return false;
}

bool isEmpty(Stack *s){
    return s->top == NULL;
}

Node* createNode(int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void push(Stack* s, int value){
    Node* newNode = createNode(value);
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s){
    Node* temp;
    temp = s->top;
    int tempValue = temp->data;
    s->top = temp->next;
    free(temp);
    return tempValue;
}

int peek(Stack *s){
    if(!isEmpty(s)){
        return s->top->data;
    }
}

// void display(Stack *s){
//     Node* trav = s->top;
//     while(trav!=NULL){
//         printf("%d ", trav->data);
//         trav = trav->next;
//     }
// }

void display(Stack *s){
    Node* trav = s->top;
    Stack *temp = initialize();
    int data;
    while(!isEmpty(s)){
        data = pop(s);
        printf("data: %d", data);
        push(temp, data);
    }

    while(!isEmpty(temp)){
        push(s, pop(temp));
    }
}

void displayMenu(){
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter: ");
}
