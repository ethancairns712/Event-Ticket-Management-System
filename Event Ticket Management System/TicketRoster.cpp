#include "TicketRoster.h"
#include <iostream>
using namespace std;

const string eventData[] = {
    "E1,Deftones,CONCERT,Wells Fargo Center,2025-01-15T20:00,50.0,150",
    "E2,MJ The Musical,THEATER,Academy of Music,2025-02-01T18:30,75.0,100",
    "E3,DePaul Blue Demons at Villanova Wildcats Women's Basketball,SPORTS,Finneran Pavilion,2025-03-10T15:00,30.0,200",
    "E4,Jay Pharoah,COMEDY,Punch Line Philly,2025-01-20T21:00,40.0,120",
    "E5,Post Malone,CONCERT,Citizens Bank Park,2025-04-05T19:00,60.0,80"
};

// Constructor
TicketRoster::TicketRoster() {
    parse();
}

// Destructor
TicketRoster::~TicketRoster() {
    for (int i = 0; i <= lastIndex; ++i) {
        delete eventList[i];
    }
}

// Parse event data and add to roster
void TicketRoster::parse() {
    for (string data : eventData) {
        int start = 0;
        int end;

        end = data.find(",", start);
        string eventID = data.substr(start, end - start);

        start = end + 1;
        end = data.find(",", start);
        string eventName = data.substr(start, end - start);

        start = end + 1;
        end = data.find(",", start);
        string eventTypeStr = data.substr(start, end - start);

        EventType eventType;
        if (eventTypeStr == "CONCERT") eventType = CONCERT;
        else if (eventTypeStr == "THEATER") eventType = THEATER;
        else if (eventTypeStr == "SPORTS") eventType = SPORTS;
        else eventType = COMEDY;

        start = end + 1;
        end = data.find(",", start);
        string venue = data.substr(start, end - start);

        start = end + 1;
        end = data.find(",", start);
        string dateTime = data.substr(start, end - start);

        start = end + 1;
        end = data.find(",", start);
        double ticketPrice = stod(data.substr(start, end - start));

        start = end + 1;
        int ticketsAvailable = stoi(data.substr(start));

        addEvent(eventID, eventName, eventType, venue, dateTime, ticketPrice, ticketsAvailable);
    }
}

// Add event
void TicketRoster::addEvent(string eventID, string eventName, EventType eventType, string venue, string dateTime, double ticketPrice, int ticketsAvailable) {
    eventList[++lastIndex] = new Event(eventID, eventName, eventType, venue, dateTime, ticketPrice, ticketsAvailable);
}

// Remove event by ID
void TicketRoster::removeEvent(string eventID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (eventList[i]->getEventID() == eventID) {
            delete eventList[i];
            eventList[i] = eventList[lastIndex--];
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Event ID: " << eventID << " not found." << endl;
    }
}

// Print all events
void TicketRoster::printAllEvents() {
    if (lastIndex == -1) {
        cout << "No events available!" << endl;
        return;
    }
    cout << "********** ALL EVENTS **********" << endl;
    for (int i = 0; i <= lastIndex; ++i) {
        eventList[i]->print();
    }
    cout << "********************************" << endl;
}
// Print events by type
void TicketRoster::printEventsByType(EventType eventType) {
    string type;
    switch (eventType) {
    case CONCERT: type = "Concerts"; break;
    case THEATER: type = "Theater Shows"; break;
    case SPORTS: type = "Sports Events"; break;
    case COMEDY: type = "Comedy Shows"; break;
    }
    cout << "********** " << type << " **********" << endl;
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (eventList[i]->getEventType() == eventType) {
            eventList[i]->print();
            found = true;
        }
    }
    if (!found) {
        cout << "No " << type << " available!" << endl;
    }
    cout << "*********************************" << endl;
}
// Print events below a price
void TicketRoster::printEventsBelowPrice(double priceLimit) {
    cout << "********** EVENTS BELOW $" << priceLimit << " **********" << endl;
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (eventList[i]->getTicketPrice() <= priceLimit) {
            eventList[i]->print();
            found = true;
        }
    }
    if (!found) {
        cout << "No events available below $" << priceLimit << "!" << endl;
    }
    cout << "****************************************" << endl;
}