#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define EMPTY '~'
#define DELETED '!'
#define MAX 211

/*********************************/
/*    USER-DEFINED DATA TYPES    */
/*********************************/
typedef struct {
    char elem;
    int frequency;
} Element;

typedef Element Dictionary[MAX];

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D);
int hash(char elem);

/*********************************/
/*          YOUR TASKS           */
/*********************************/

void insert(Dictionary D, char elem);
void delete(Dictionary D, char elem);
bool isMember(Dictionary D, char elem);
bool isAnagram(char* s, char* t);

int main(void) {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    if (isAnagram(s1, s2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", s1, s2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", s1, s2);
    }

    return 0;
}

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i].elem = EMPTY;
        D[i].frequency = 0;
    }
}

int hash(char elem) {
    return ((int)elem) % MAX;
}

/*********************************/
/*          YOUR TASKS           */
/*********************************/


void insert(Dictionary d, char elem) {
    int key = hash(elem);
    int original = key;
    
    while(d[key].elem != EMPTY && d[key].elem != DELETED){
        if(d[key].elem == elem){
            d[key].frequency++;
            return;
        }
        key = (key+1) % MAX;
        
        if(key == original){
            return;
        }
    }
    
    d[key].elem = elem;
    d[key].frequency = 1;
}

void delete(Dictionary d, char elem) {
    int key = hash(elem);
    int original = key;
    
    while(d[key].elem != EMPTY){
        if(d[key].elem == elem){
            d[key].frequency--;
            if(d[key].frequency == 0){
                d[key].elem = DELETED;
            }
            
        return;
        }
        key = (key+1)%MAX;
        if(key == original) break;
    }
}

bool isMember(Dictionary d, char elem) {
    int key = hash(elem);
    int original = key;
    while(d[key].elem!=EMPTY){
        if(d[key].elem == elem && d[key].frequency > 0){
            return true;
        }
        key = (key+1)%MAX;
        if(key == original) break;
    }
    return false;
}

bool isAnagram(char* s, char* t) {
    Dictionary d;
    initDict(d);
    
    for(int i=0; s[i]!='\0'; i++){
        insert(d, s[i]);
    }
    
    for(int i=0; t[i]!='\0'; i++){
        if(!isMember(d, t[i])){
            return false;
        }
        delete(d, t[i]);
    }
    
    return true;
}