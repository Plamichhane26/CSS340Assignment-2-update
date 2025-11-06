#include "VirtualEvent.h"

VirtualEvent::VirtualEvent()
    : Event(), virtualVenue(""), audience("") {}

VirtualEvent::VirtualEvent(const std::string& n,
                         const std::string& d,
                         double r,
                         const std::string& vvenue,
                         const std::string& aud)
    : Event(n, d, r), virtualVenue(vvenue), audience(aud) {}

// Copy constructor
VirtualEvent::VirtualEvent(const VirtualEvent& other)
    : Event(other), virtualVenue(other.virtualVenue), audience(other.audience) {}

// Assignment operator
VirtualEvent& VirtualEvent::operator=(const VirtualEvent& other) {
    if (this != &other) {
        Event::operator=(other);
        virtualVenue = other.virtualVenue;
        audience = other.audience;
    }
    return *this;
}

std::string VirtualEvent::sellTicket(int quantity) {
    if (quantity <= 0) return "Quantity must be >= 1.";
    ticketsSold += quantity; // no capacity limit
    return "Sold " + std::to_string(quantity) + " virtual ticket(s).";
}

void VirtualEvent::display(std::ostream& os) const {
    os << *this;
}

bool VirtualEvent::operator==(const VirtualEvent& other) const {
    return Event::operator==(other) &&
           virtualVenue == other.virtualVenue &&
           audience == other.audience;
}

std::ostream& operator<<(std::ostream& os, const VirtualEvent& event) {
    os << static_cast<const Event&>(event);
    os << "Type: Virtual\n"
       << "Virtual Venue: " << event.virtualVenue << "\n"
       << "Audience: " << event.audience << "\n";
    return os;
}
