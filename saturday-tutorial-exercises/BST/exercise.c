#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

typedef struct {
	int book_id;
	String book_name;
} Book;

typedef struct node {
	Book book;
	struct node *left;
	struct node *right;
} *BST;

//exercise 1
void insertNode(BST *root, Book newBook){
    BST *trav;
    for(trav=root; *trav!=NULL;){
        trav = (newBook.book_id > (*trav)->book.book_id) ? &(*trav)->right : &(*trav)->left; 
    }
    if(*trav==NULL){
        *trav = malloc(sizeof(struct node));
        (*trav)->book = newBook;
        (*trav)->left = NULL;
        (*trav)->right = NULL;
    }
}

//exercise 2
void displayBook(BST root, int book_id){
	BST trav = root;
	while(trav!=NULL){
	    if(trav->book.book_id < book_id && trav->book.book_id != book_id){
	        trav = trav->right;
	    }
	    else if(trav->book.book_id > book_id && trav->book.book_id != book_id){
	        trav = trav->left;
	    }
	    else{
	        printf("Book: %s | Book ID: %d", trav->book.book_name, trav->book.book_id);
	        return;
	    }
	}
}

