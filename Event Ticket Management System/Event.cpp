#include "Event.h"
#include <iostream>
using namespace std;

// Constructor implementation
Event::Event(string eventID, string eventName, EventType eventType, string venue, string dateTime, double ticketPrice, int ticketsAvailable) {
    this->eventID = eventID;
    this->eventName = eventName;
    this->eventType = eventType;
    this->venue = venue;
    this->dateTime = dateTime;
    this->ticketPrice = ticketPrice;
    this->ticketsAvailable = ticketsAvailable;
}

// Accessors
string Event::getEventID() { return this->eventID; }
string Event::getEventName() { return this->eventName; }
EventType Event::getEventType() { return this->eventType; }
string Event::getVenue() { return this->venue; }
string Event::getDateTime() { return this->dateTime; }
double Event::getTicketPrice() { return this->ticketPrice; }
int Event::getTicketsAvailable() { return this->ticketsAvailable; }

// Mutators
void Event::setEventID(string eventID) { this->eventID = eventID; }
void Event::setEventName(string eventName) { this->eventName = eventName; }
void Event::setEventType(EventType eventType) { this->eventType = eventType; }
void Event::setVenue(string venue) { this->venue = venue; }
void Event::setDateTime(string dateTime) { this->dateTime = dateTime; }
void Event::setTicketPrice(double ticketPrice) { this->ticketPrice = ticketPrice; }
void Event::setTicketsAvailable(int ticketsAvailable) { this->ticketsAvailable = ticketsAvailable; }

// Print event details
void Event::print() {
    cout << "------------------------------------------" << endl;
    cout << "Event ID          : " << this->getEventID() << endl;
    cout << "Event Name        : " << this->getEventName() << endl;
    cout << "Event Type        : ";
    switch (this->getEventType()) {
    case CONCERT:
        cout << "Concert";
        break;
    case THEATER:
        cout << "Theater";
        break;
    case SPORTS:
        cout << "Sports";
        break;
    case COMEDY:
        cout << "Comedy";
        break;
    }
    cout << endl;
    cout << "Venue             : " << this->getVenue() << endl;
    cout << "Date and Time     : " << this->getDateTime() << endl;
    cout << "Ticket Price      : $" << this->getTicketPrice() << endl;
    cout << "Tickets Available : " << this->getTicketsAvailable() << endl;
    cout << "------------------------------------------" << endl;
}