#pragma once
#include "Event.h"

class TicketRoster {
private:
    Event* eventList[5];
    int lastIndex = -1;

    void parse();

public:
    TicketRoster();
    ~TicketRoster();

    void addEvent(string eventID, string eventName, EventType eventType, string venue, string dateTime, double ticketPrice, int ticketsAvailable);
    void removeEvent(string eventID);
    void printAllEvents();
    void printEventsByType(EventType eventType);
    void printEventsBelowPrice(double priceLimit);

    int getLastIndex() const { return lastIndex; }
    string getEventIDByIndex(int index) const { return eventList[index]->getEventID(); }
};