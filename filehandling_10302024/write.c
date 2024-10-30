#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main(){
    Person list [5];

    list[0] = newPerson("Choi", 12);
    list[1] = newPerson("Jans", 12);
    list[2] = newPerson("Chewy", 12);
    list[3] = newPerson("Luwi", 12);
    list[4] = newPerson("Jeyel", 12);

    FILE *fp;

    fp = fopen("person_file.dat", "wb");

    if(fp!=NULL){
        fwrite(list+2, sizeof(Person), 2, fp);
    }

    fclose(fp);

    return 0;
}