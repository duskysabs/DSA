#ifndef FLIGHT_H
#define FLIGHT_H

typedef char String[20];

typedef struct{
    int hour;
    int minute;
}Schedule;

typedef struct{
    String destName;
    int destPriority;
} Destination;

typedef struct{
    int flightCode;
    String aircraft;
    Schedule flightSched;
    Destination flightDest;
} Flight;

Flight newFlight(int flightCode, char* aircraft, Schedule flightSched, Destination flightDest);
Schedule newSched(int minute, int hour);
Destination newDestination(char* destName, int destPriority);
void displayFlight(Flight f);

#endif