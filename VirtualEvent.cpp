#include "VirtualEvent.h"

VirtualEvent::VirtualEvent()
    : Event("", "", 0.0), virtualVenue(""), audience("") {}

VirtualEvent::VirtualEvent(const std::string& n,
                           const std::string& d,
                           double r,
                           const std::string& vvenue,
                           const std::string& aud)
    : Event(n, d, r), virtualVenue(vvenue), audience(aud) {}

std::string VirtualEvent::sellTicket(int quantity) {
    if (quantity <= 0) return "Quantity must be >= 1.";
    ticketsSold += quantity; // no capacity limit
    return "Sold " + std::to_string(quantity) + " virtual ticket(s).";
}

void VirtualEvent::display(std::ostream& os) const {
    Event::display(os);
    os << "Type: Virtual\n"
       << "Virtual Venue: " << virtualVenue << "\n"
       << "Audience: " << audience << "\n";
}
