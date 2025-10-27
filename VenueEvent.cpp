#include "VenueEvent.h"

VenueEvent::VenueEvent()
    : Event("", "", 0.0), venue(""), dateTime(""), capacity(0) {}

VenueEvent::VenueEvent(const std::string& n,
                       const std::string& d,
                       double r,
                       const std::string& v,
                       const std::string& dt,
                       int cap)
    : Event(n, d, r), venue(v), dateTime(dt), capacity(cap) {}

std::string VenueEvent::sellTicket(int quantity) {
    if (quantity <= 0) return "Quantity must be >= 1.";
    if (quantity > capacity) return "Not enough capacity.";
    ticketsSold += quantity;
    capacity -= quantity;
    return "Sold " + std::to_string(quantity) + " ticket(s). Remaining: " + std::to_string(capacity);
}

void VenueEvent::display(std::ostream& os) const {
    Event::display(os);
    os << "Type: Venue\n"
       << "Venue: " << venue << "\n"
       << "Date/Time: " << dateTime << "\n"
       << "Capacity: " << capacity << "\n";
}
