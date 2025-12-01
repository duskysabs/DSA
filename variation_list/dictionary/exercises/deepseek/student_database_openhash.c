#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 7
#define NAME_SIZE 20
#define ID_SIZE 10

typedef struct {
    char id[ID_SIZE];
    char name[NAME_SIZE];
    float gpa;
} Student;

typedef struct node {
    Student data;
    struct node *next;
} Node;

typedef struct {
    Node *table[TABLE_SIZE];
    int count;
} StudentDB;

// 1. Hash function - sum of first 3 chars of ID mod TABLE_SIZE
int hash(char *id);
void initDB(StudentDB *db);
void addStudent(StudentDB *db, char *id, char *name, float gpa);
Student* searchStudent(StudentDB *db, char *id);
int deleteStudent(StudentDB *db, char *id);
void displayAll(StudentDB db);
void displayBuckets(StudentDB db);
void displayStats(StudentDB db);
void freeDB(StudentDB *db);

int main() {
    StudentDB db;
    initDB(&db);
    
    printf("=== Student Record System - Open Hashing ===\n");
    
    // Add test students
    addStudent(&db, "S1001", "Alice Johnson", 3.8);
    addStudent(&db, "S1002", "Bob Smith", 3.2);
    addStudent(&db, "S1003", "Carol Davis", 3.9);
    addStudent(&db, "S2001", "David Wilson", 2.8);
    addStudent(&db, "S2002", "Eva Brown", 3.5);
    addStudent(&db, "S3001", "Frank Miller", 3.1);
    
    printf("\n1. All Students:\n");
    displayAll(db);
    
    printf("\n2. Display by Buckets:\n");
    displayBuckets(db);
    
    printf("\n3. Database Statistics:\n");
    displayStats(db);
    
    printf("\n4. Searching for S1002:\n");
    Student *found = searchStudent(&db, "S1002");
    if(found != NULL) {
        printf("   Found: %s - %s (GPA: %.1f)\n", found->id, found->name, found->gpa);
    } else {
        printf("   Student not found!\n");
    }
    
    printf("\n5. Deleting S1003:\n");
    if(deleteStudent(&db, "S1003")) {
        printf("   Deleted successfully!\n");
    } else {
        printf("   Student not found!\n");
    }
    
    printf("\n6. Final Database State:\n");
    displayBuckets(db);
    
    printf("\n7. Final Statistics:\n");
    displayStats(db);
    
    // Test collision
    printf("\n8. Testing collision - adding S7007:\n");
    addStudent(&db, "S7007", "Grace Lee", 3.7);
    displayBuckets(db);
    
    // freeDB(&db);
    return 0;
}

int hash(char *id) {
    int sum = 0;
    for(int i = 0; i < 3 && id[i] != '\0'; i++) {
        sum += id[i];
    }
    return sum % TABLE_SIZE;
}

void initDB(StudentDB *db) {
    for(int i = 0; i < TABLE_SIZE; i++) {
        db->table[i] = NULL;
    }
    db->count = 0;
}

Node* createNode(char *id, char *name, float gpa) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL) {
        strcpy(newNode->data.id, id);
        strcpy(newNode->data.name, name);
        newNode->data.gpa = gpa;
        newNode->next = NULL;
    }
    return newNode;
}

void addStudent(StudentDB *db, char *id, char *name, float gpa) {
    int pos = hash(id);
    Node* newNode = createNode(id, name, gpa);
    newNode->next = db->table[pos];
    db->table[pos] = newNode;
    db->count++;
}

Student* searchStudent(StudentDB *db, char *id) {
    int pos = hash(id);
    Node* trav = db->table[pos];
    while(trav!=NULL){
        if(strcmp(trav->data.id, id) == 0){
            return &(trav->data);
        }
        trav = trav->next;
    }
    return 0;
}

int deleteStudent(StudentDB *db, char *id) {
    // TODO: Return 1 if deleted, 0 if not found
    int pos = hash(id);
    
    if(strcmp(db->table[pos]->next->data.id, id)){
            db->table[pos] = db->table[pos]->next;
            db->count--;
            return 1;
        }   
        
    Node* trav = db->table[pos];
    while(trav!=NULL){
        if(strcmp(trav->next->data.id, id)){
            Node* temp = trav->next;
            trav->next = temp->next;
            db->count--;
            free(temp);
            return 1;
        }
        trav = trav->next;
    }
    return 0;
}

void displayAll(StudentDB db) {
    printf("All Students (%d):\n", db.count);
    for(int i=0; i<TABLE_SIZE; i++){
        Node *trav = db.table[i];
        while(trav!=NULL){
            printf("%s - %s (GPA: %.2f)\n", trav->data.id, trav->data.name, trav->data.gpa);
            trav = trav->next;
        }
    }
}

void displayBuckets(StudentDB db) {
    // TODO: Display by hash buckets
    for(int i=0; i<TABLE_SIZE; i++){
        printf("Bucket %d: ", i);
        Node *trav = db.table[i];
        if(trav==NULL){
            printf("EMPTY");
        }
        else{
                while(trav!=NULL){
                printf("%s ", trav->data.id);
                if(trav->next!=NULL){
                    printf("-> ");
                }
                trav = trav->next;
            }
        }
        printf("\n");
    }
}

void displayStats(StudentDB db) {
    printf("=== Database Statistics ===\n");
    printf("Total students: %d\n", db.count);
    printf("Load factor: %.2f\n", (float)db.count / TABLE_SIZE);
    
    int longestChain = 0;
    int emptyBuckets = 0;
    int totalChains = 0;
    int nonEmptyBuckets = 0;
    
    for(int i = 0; i < TABLE_SIZE; i++) {
        int chainLength = 0;
        Node *trav = db.table[i];
        
        while(trav != NULL) {
            chainLength++;
            trav = trav->next;
        }
        
        if(chainLength > longestChain) {
            longestChain = chainLength;
        }
        
        if(chainLength == 0) {
            emptyBuckets++;
        } else {
            nonEmptyBuckets++;
            totalChains += chainLength;
        }
    }
    
    printf("Longest chain: %d students\n", longestChain);
    printf("Empty buckets: %d\n", emptyBuckets);
    printf("Non-empty buckets: %d\n", nonEmptyBuckets);
    
    if(nonEmptyBuckets > 0) {
        printf("Average chain length: %.2f\n", (float)totalChains / nonEmptyBuckets);
    } else {
        printf("Average chain length: 0.00\n");
    }
    
    // Show bucket distribution
    printf("\nBucket Distribution:\n");
    for(int i = 0; i < TABLE_SIZE; i++) {
        int chainLength = 0;
        Node *trav = db.table[i];
        while(trav != NULL) {
            chainLength++;
            trav = trav->next;
        }
        printf("  Bucket %d: %d student(s)\n", i, chainLength);
    }
}

void freeDB(StudentDB *db) {
    printf("\nFreeing database memory...\n");
    int nodesFreed = 0;
    
    for(int i = 0; i < TABLE_SIZE; i++) {
        Node *trav = db->table[i];
        while(trav != NULL) {
            Node *temp = trav;
            trav = trav->next;
            free(temp);
            nodesFreed++;
        }
        db->table[i] = NULL;
    }
    
    db->count = 0;
    printf("Freed %d nodes. Database cleared.\n", nodesFreed);
}