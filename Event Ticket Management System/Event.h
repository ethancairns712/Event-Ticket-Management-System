#pragma once
#include <string>
using namespace std;

enum EventType { CONCERT, THEATER, SPORTS, COMEDY };

class Event {
private:
    string eventID;
    string eventName;
    EventType eventType;
    string venue;
    string dateTime;
    double ticketPrice;
    int ticketsAvailable;

public:
    // Constructor
    Event(string eventID, string eventName, EventType eventType, string venue, string dateTime, double ticketPrice, int ticketsAvailable);

    // Accessors
    string getEventID();
    string getEventName();
    EventType getEventType();
    string getVenue();
    string getDateTime();
    double getTicketPrice();
    int getTicketsAvailable();

    // Mutators
    void setEventID(string eventID);
    void setEventName(string eventName);
    void setEventType(EventType eventType);
    void setVenue(string venue);
    void setDateTime(string dateTime);
    void setTicketPrice(double ticketPrice);
    void setTicketsAvailable(int ticketsAvailable);

    // Print event details
    void print();
};