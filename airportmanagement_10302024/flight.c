#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight.h"

Flight newFlight(int flightCode, char* aircraft, Schedule flightSched, Destination flightDest){
    Flight f;

    f.flightCode = flightCode;
    strcpy(f.aircraft, aircraft);
    f.flightSched = flightSched;
    f.flightDest = flightDest;

    return f;
}
Schedule newSched(int minute, int hour){
    Schedule s;

    s.minute = minute;
    s.hour = hour;

    return s;
}
Destination newDestination(char* destName, int destPriority){
    Destination d;

    strcpy(d.destName, destName);
    d.destPriority = destPriority;

    return d;
}

void displayFlight(Flight f){
    printf("Flight Details: %-10d - %-10s - %-10d\n", f.flightCode, f.flightDest.destName, f.flightDest.destPriority);
    printf("Time: %d:%d\n", f.flightSched.hour, f.flightSched.minute);
    printf("Aircraft Details: %-10s\n\n", f.aircraft);
}
