#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

Person newPerson(char *name, int age){
    Person newPerson;
    strcpy(newPerson.name, name);
    newPerson.age = age;
    return newPerson;
}

    void displayPerson(Person p){
        printf("%-20s - %d\n", p.name, p.age);
}
