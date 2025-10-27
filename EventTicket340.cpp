// TO DO: Implementation of EventTicket340 functions
#include <iostream>
#include <string>
#include "EventTicket340.h"

// TO DO: implement constructor
EventTicket340::EventTicket340() = default;

// TO DO: implement destructor
EventTicket340::~EventTicket340() = default;

void EventTicket340::createOrganizer(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){
	// TO DO: implement function
	organizer = Organizer(username, email, password, bio, profilePicture);

}
Organizer EventTicket340::getOrganizer() {
    return organizer;
}

Organizer EventTicket340::getOrganizer() const{
	// TO DO: implement function
}
#endif
