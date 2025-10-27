#ifndef VIRTUAL_EVENT_H
#define VIRTUAL_EVENT_H

#include "Event.h"
#include <string>
#include <iostream>

class VirtualEvent : public Event {
private:
    std::string virtualVenue;  // e.g., "Zoom"
    std::string audience;      // e.g., "Public"

public:
    VirtualEvent();
    VirtualEvent(const std::string& n,
                 const std::string& d,
                 double r,
                 const std::string& vvenue,
                 const std::string& aud);

    std::string sellTicket(int quantity) override;
    void display(std::ostream& os = std::cout) const override;
};

#endif
