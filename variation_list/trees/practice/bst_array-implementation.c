#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY -1

typedef struct{
    int *data;
    int size;
}BST;


void initialize(BST *T, int size){
    T->data = malloc(sizeof(int)*size);
    T->size = size;
    for(int i=0; i<size; i++){
        T->data[i] = EMPTY;
    }
}

void insert(BST *T, int data){
    int index = 0;
    
    while(index<T->size && T->data[index] != EMPTY){
        if(T->data[index] > data) index = (2*index)+1; //going left if data inserted is less than the data in specific index
        else if(T->data[index] < data) index = (2*index)+2; //going right if data inserted is greather than the data in specific index
        else return; //duplicate value 
    }
    
    if(index<T->size) T->data[index] = data; //insertion
    else return;
}

bool search(BST T, int data){
    int index = 0;
    while(index<T.size && T.data[index] != EMPTY){
        if(T.data[index] == data) return true;
        if(data < T.data[index]) index = (2*index)+1;
        else index = (2*index)+2;
    }
    return false; 
}


int main() {
    BST tree;
    int size = 15; // max nodes
    initialize(&tree, size);

    // Insert some elements
    insert(&tree, 50);
    insert(&tree, 30);
    insert(&tree, 70);
    insert(&tree, 20);
    insert(&tree, 40);
    insert(&tree, 60);
    insert(&tree, 80);

    // Print the array representing BST
    printf("Array-based BST:\n");
    for(int i = 0; i < tree.size; i++) {
        if(tree.data[i] != EMPTY) printf("%d ", tree.data[i]);
        else printf("_ "); // indicate empty slot
    }
    printf("\n");

    // Search for some elements
    int keys[] = {40, 99, 60, 15};
    for(int i = 0; i < 4; i++) {
        if(search(tree, keys[i])) printf("%d found in BST\n", keys[i]);
        else printf("%d NOT found in BST\n", keys[i]);
    }

    // Free memory
    free(tree.data);

    return 0;
}