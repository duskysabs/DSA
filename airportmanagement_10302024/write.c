#include <stdio.h>
#include <stdlib.h>
#include "flight.h"

int main(){
    Flight list [5];

    list[0] = newFlight(1, "Boeing", newSched(10, 30), newDestination("Manila", 1));
    list[1] = newFlight(1, "Airbus", newSched(10, 30), newDestination("Cebu", 2));
    list[2] = newFlight(1, "Bombardier", newSched(10, 30), newDestination("Davao", 3));
    list[3] = newFlight(1, "Cessna", newSched(10, 30), newDestination("Albay", 4));
    list[4] = newFlight(1, "Jet", newSched(10, 30), newDestination("Quezon", 5));

    FILE *fp = fopen("flight_file.dat", "wb");

    if(fp!=NULL){
        fwrite(list, sizeof(Flight), 5, fp);
    }

    fclose(fp);
    return 0;
}