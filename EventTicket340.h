#include "LinkedBag.h"
// TO DO include necessary libraries
#ifndef EVENTTICKET340_H
#define EVENTTICKET340_H

#include <string>
#include <memory>
#include "Organizer.h"

// This class only contains a single organizer
class EventTicket340 {
private:
    Organizer organizer;

public:
    // Constructors and destructor (BIG 3)
    EventTicket340();
    EventTicket340(const EventTicket340& other);  // Copy constructor
    ~EventTicket340();

    // Assignment operator (BIG 3)
    EventTicket340& operator=(const EventTicket340& other);

    // Create a new organizer profile
    void createOrganizer(const std::string& username, 
                        const std::string& email, 
                        const std::string& password, 
                        const std::string& bio, 
                        const std::string& profilePicture);

    // Retrieve the organizer object
    const Organizer& getOrganizer() const;
};

#endif