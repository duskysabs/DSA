#include <stdio.h>
#include <stdlib.h>
#include "flight.h"

int main(){
    FILE *fp;
    Flight f;

    fp = fopen("flight_file.dat", "rb");

    if(fp!=NULL){
        while(fread(&f, sizeof(Flight), 1, fp)){
            displayFlight(f);
            printf("\n");
        }
    }

    fclose(fp);

    return 0;
}