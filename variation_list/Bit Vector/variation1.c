#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void Delete(unsigned char *set, int element);
bool find(unsigned char *set, int element);
unsigned char Union(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned difference(unsigned char A, unsigned char B);
void display(unsigned char set);


int main() {
    char A;
    initialize(&A);
    
    // insert(&A, 2);
    insert(&A, 1);
    insert(&A, 6);
    insert(&A, 7);
    
    Delete(&A, 1);
    
    find(&A, 3) ? printf("found!\n") : printf("not found!\n");
    
    display(A);

    return 0;
}

void initialize(unsigned char *set){
    *set = 0;
}
void insert(unsigned char *set, int element){
    if(element < 8){
        unsigned int mask = 1 << element;
        *set = Union(*set, mask);
    } else {
        printf("Element size is not valid.\n");
    }
}
void Delete(unsigned char *set, int element){
    if(element < 8){
        unsigned int mask = 1 << element;
        *set = difference(*set, mask);
    } else {
        printf("Element size is not valid.\n");
    }
}
bool find(unsigned char *set, int element){
    if(element < 8){
        unsigned int mask = 1 << element;
        return (*set & mask) ? true : false;
    } else {
        printf("None was found.\n");
        return false;
    }
}
unsigned char Union(unsigned char A, unsigned char B){
    return A ^ B;
}
unsigned char intersection(unsigned char A, unsigned char B){
    return A & B;
}
unsigned difference(unsigned char A, unsigned char B){
    return A & ~(B);
}

void display(unsigned char set){
    printf("char A = %d\n", set);
    printf("Printing Binary:\n");
    for(int i = 7; i >= 0 ; i--){
        printf("%d ", (set & (1 << i)) ? 1 : 0);
    }
    printf("\nPrinting Elements:\n");
    for(int i = 0; i < 8 ; i++){
        if(set & (1 << i)){
            printf("%d ", i);
        }
    }
    printf("\n");
}