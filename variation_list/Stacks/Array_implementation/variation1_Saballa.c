#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int top;
}Stack;

Stack* initialize();
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack* s);
int peek(Stack* s);
int top(Stack* s);
void display(Stack* s);
void displayArr(Stack* s);
void displayMenu();

int main(){
    Stack *s = initialize();
    int choice, value;
    do{
        displayMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter a value: ");
                scanf("%d", &value);
                push(s, value);
                printf("\n");
                break;
            case 2:
                printf("retrieved value: %d\n\n", value = pop(s));
                break;
            case 3:
                printf("value: %d\n\n", value = peek(s));
                break;
            case 4:
                printf("top: %d\n\n", value = top(s));
                break;
            case 5:
                display(s);
                break;
            case 6:
                displayArr(s);
                break;
        }
    }while(choice<7);
}

Stack* initialize(){
    Stack* s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack *s){ return s->top == MAX-1; }
bool isEmpty(Stack *s){ return s->top == -1; }
void push(Stack* s, int value){
    if(!isFull(s)){
        s->items[++s->top] = value;
    }
    else{
        printf("stack is full.");
    }
}
int pop(Stack *s){
    if(!isEmpty(s)){
        return s->items[s->top--];
    }
    else{
        return -1;
    }
}
int peek(Stack *s){
    if(!isEmpty(s)){
        return s->items[s->top];
    }
}

int top(Stack *s){
    return s->top;
}

void displayArr(Stack *s){
    printf("Array Data: ");
    for(int i=0; i<=s->top; i++){
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

void display(Stack *s){
    Stack *temp = initialize();
    printf("Data: ");
    while(!isEmpty(s)){
        int value = pop(s);
        printf("%d ", value);
        push(temp, value);
    }
    
    while(!isEmpty(temp)){
        push(s, pop(temp));
    }
    printf("\n\n");
}

void displayMenu(){
    printf("1.Push\n2.Pop\n3.Peek\n4.Top\n5.Display\n6.Display Test\nChoice: ");
}