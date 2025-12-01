#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20

typedef char Code[4]; // terminating character in the end

typedef struct{
    Code code;
    int next;
}Cell, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
}VHeap;

void initialize(VHeap *V);
int allocSpace(VHeap *V);
int hashCode(Code code);
void insertAirport(VHeap* V, Code code);
void display(VHeap V);

int main(){
    VHeap V;
    initialize(&V);

    Code setA[] = {"JFK", "LAX", "SFO", "CDG", "LHR", "NRT", "ATL", "DXB", "PEK", "MIA", "SYD", "ORD"};

    for(int i=0; i<(sizeof(setA) / 4); i++){
        printf("Adding %s. \n", setA[i]);
        insertAirport(&V, setA[i]);
    }
    
    display(V);
}

void initialize(VHeap *V){
    for(int i=0; i< MAX/2; i++){
        strcpy(V->H[i].code, "");
        V->H[i].next = -1;
    }

    V->avail = MAX/2;
    for(int i=MAX/2; i<MAX; i++){
        strcpy(V->H[i].code, "");
        V->H[i].next = i+1;
    }

    V->H[MAX-1].next = -1;
}

int allocSpace(VHeap *V){
    int ret = V->avail;
    if(ret!=-1){
        V->avail = V->H[ret].next;
    }
    else{
        printf("unable to allocate space.");
    }
    return ret;
}

int hashCode(Code code){
    int hash = ((code[0] - 'A') * 26 * 26 + (code[1] - 'A') * 26 + (code[2]-'A')) % 10;
    return hash;
}

void insertAirport(VHeap *V, Code code){
    int position = hashCode(code);

    if(strcmp(V->H[position].code, "") == 0){
        strcpy(V->H[position].code, code);
    } 
    
    else{
        int newCell = allocSpace(V);
        if(newCell!=-1){
            strcpy(V->H[newCell].code, code);
            V->H[newCell].next = -1;
            if(V->H[position].next == -1){
                V->H[position].next = newCell;
            }
            else{
                int *curr = &V->H[position].next;
                while(*curr!=-1){
                    curr = &V->H[*curr].next;
                }
                *curr = newCell;
            }
        } else{
            printf("unable to insert\n");
        }
    }
    printf("hash for %s: %d\n", code, position);
}

void display(VHeap V){
    printf("\nAvail = %d\n", V.avail);
    printf("Primary List:\n");
    printf("%3s|%3s|%3s\n", "index", "code", "next");
    for(int i=0; i<MAX/2; i++){
        printf("%3d|%3s|%3d\n", i, V.H[i].code, V.H[i].next);
    }

    printf("Secondary List:\n");
    printf("%3s|%3s|%3s\n", "index", "code", "next");
    for(int i=MAX/2; i<MAX; i++){
        printf("%3d|%3s|%3d\n", i, V.H[i].code, V.H[i].next);
    }
}