#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int elem;
    struct Node *lc;
    struct Node *rc;
}Node, *BST;

void insertData(BST* T, int elem){
    BST* trav;
    for(trav = T;  *trav!=NULL && (*trav)->elem != elem;){
        trav = ((*trav)->elem > elem) ? &(*trav)->lc : &(*trav)->rc;
    }
    
    if(*trav == NULL){
        *trav = (BST)calloc(1, sizeof(Node));
        (*trav)->elem = elem;
    }
}

bool searchData(BST T, int elem){
    if(T == NULL){
        return false;
    }
    
    if(T->elem == elem){
        return true;
    }
    
    if(elem > T->elem){
        return searchData(T->rc, elem);
    }
    return searchData(T->lc, elem);
}

void inorder(BST T){
    if(T!=NULL){
        inorder(T->lc);
        printf("%d", T->elem);
        inorder(T->rc);
    }
}

void preorder(BST T){
    if(T!=NULL){
        printf("%d", T->elem);
        preorder(T->lc);
        preorder(T->rc);
    }
}

void postorder(BST T){
    if(T!=NULL){
        postorder(T->lc);
        postorder(T->rc);
        printf("%d", T->elem);
    }
}

BST* findMin(BST* T){
    BST* trav = T;
    while((*trav)->lc!=NULL){
        trav = &(*trav)->lc;
    }
    return trav;
}

void deleteData(BST* T, int elem){
    BST* trav;
    
    for(trav=T; *trav!=NULL && (*trav)->elem != elem){
        trav = ((*trav)->elem > elem) ? &(*trav)->lc : &(*trav)->rc;
    }
    
    if(*trav == NULL){
        printf("elem not found!");
        return;
    }
    
    BST temp = *trav;
    
    if(temp->lc == NULL && temp->rc == NULL){
        *trav = NULL;
        free(temp);
    }

    else if(temp->lc == NULL && temp->rc != NULL){
        *trav = temp->rc;
        free(temp);
    }

    else if(temp->lc != NULL && temp->rc == NULL){
        *trav = temp->lc;
        free(temp);
    }

    else{
        BST* minNode = findMin(&temp->rc);
        temp->elem = (*minNode)->elem;

        BST toDelete = *minNode;
        *minNode = (*minNode)->rc;
        free(toDelete);
    }

}

BST* findMin(BST* T){
    BST* trav = T;
    while((*trav)->lc != NULL){
        trav = &(*trav)->lc;
    }
    return *trav;
}

int main(){
    BST T;
    
    insertData(&T, 5);
    insertData(&T, 6);
    insertData(&T, 2);
    insertData(&T, 4);
    insertData(&T, 3);
    
    printf("Inorder: ");
    inorder(T);
    printf("\nPreorder: ");
    preorder(T);
    printf("\nPostorder: ");
    postorder(T);
    
    printf("\n");
    bool search = searchData(T, 1);
    search ? printf("Data is found!") : printf("Data is not found.");
}