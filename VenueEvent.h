#ifndef VENUE_EVENT_H
#define VENUE_EVENT_H

#include "Event.h"
#include <string>
#include <iostream>

class VenueEvent : public Event {
private:
    std::string venue;
    std::string dateTime;
    int         capacity;

public:
    VenueEvent();
    VenueEvent(const std::string& n,
               const std::string& d,
               double r,
               const std::string& v,
               const std::string& dt,
               int cap);

    std::string sellTicket(int quantity) override;
    void display(std::ostream& os = std::cout) const override;
};

#endif
