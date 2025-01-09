/*
 * Event Ticket Management System
 * ----------------------------------
 * Description:
 * This program is designed to manage events for an online ticketing platform.
 * It allows users to add, update, remove, and display event details such as
 * event name, type, venue, date, ticket price, and ticket availability.
 * Additional features include filtering events by type, and validating event data.
 *
 * Purpose:
 * To showcase efficient event management functionality for an online
 * ticketing platform with clean modular design and user-friendly output.
 *
 * Author: Ethan Cairns
 * Date: 01/09/2025
 *
 * Components:
 * - Event.h / Event.cpp: Handles the Event class, representing individual events.
 * - TicketRoster.h / TicketRoster.cpp: Manages the collection of events and provides
 *   operations like adding, removing, and displaying events.
 * - Main.cpp: Implements the program logic, including user interaction and output.
 */

#include "TicketRoster.h"
#include <iostream>
using namespace std;

int main() {
    TicketRoster ticketRoster;

    cout << endl;
    cout << "========== EVENT TICKET MANAGEMENT SYSTEM ==========" << endl;
    cout << endl;

    cout << "Displaying all events:" << endl;
    ticketRoster.printAllEvents();
    cout << endl;

    cout << "Displaying all concerts:" << endl;
    ticketRoster.printEventsByType(CONCERT);
    cout << endl;

    cout << "Displaying events below $50:" << endl;
    ticketRoster.printEventsBelowPrice(50.0);
    cout << endl;

    cout << "Removing event with ID E3:" << endl;
    ticketRoster.removeEvent("E3");
    ticketRoster.printAllEvents();

    return 0;
}