#include <iostream>
#include <string>
#include <memory>
#include "EventTicket340.h"

// Constructor
EventTicket340::EventTicket340() = default;

// Destructor
EventTicket340::~EventTicket340() = default;

// Copy constructor (BIG 3)
EventTicket340::EventTicket340(const EventTicket340& other) 
    : organizer(other.organizer) {}

// Assignment operator (BIG 3)
EventTicket340& EventTicket340::operator=(const EventTicket340& other) {
    if (this != &other) {
        organizer = other.organizer;
    }
    return *this;
}

void EventTicket340::createOrganizer(const std::string& username, 
                                   const std::string& email, 
                                   const std::string& password, 
                                   const std::string& bio, 
                                   const std::string& profilePicture) {
    organizer = Organizer(username, email, password, bio, profilePicture);
}

const Organizer& EventTicket340::getOrganizer() const {
    return organizer;
}
