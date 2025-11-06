#include "Event.h"

Event::Event() : name(""), description(""), rating(0.0), ticketsSold(0) {}

Event::Event(const std::string& n, const std::string& d, double r)
    : name(n), description(d), rating(r), ticketsSold(0) {}

Event::Event(const Event& other)
    : name(other.name), description(other.description),
      rating(other.rating), ticketsSold(other.ticketsSold) {}

Event::~Event() {}

Event& Event::operator=(const Event& other) {
    if (this != &other) {
        name = other.name;
        description = other.description;
        rating = other.rating;
        ticketsSold = other.ticketsSold;
    }
    return *this;
}

bool Event::operator==(const Event& otherEvent) const {
    return name == otherEvent.name;
}

bool Event::operator!=(const Event& otherEvent) const {
    return !(*this == otherEvent);
}

bool Event::operator<(const Event& otherEvent) const {
    return name < otherEvent.name;
}

bool Event::operator>(const Event& otherEvent) const {
    return otherEvent < *this;
}

std::string Event::getName() const { return name; }
std::string Event::getDescription() const { return description; }
double Event::getRating() const { return rating; }
int Event::getTicketsSold() const { return ticketsSold; }

void Event::setName(const std::string& n) { name = n; }
void Event::setDescription(const std::string& d) { description = d; }
void Event::setRating(double r) { rating = r; }

void Event::display(std::ostream& os) const {
    os << *this;
}

std::ostream& operator<<(std::ostream& os, const Event& event) {
    os << "Name: " << event.name << "\n"
       << "Description: " << event.description << "\n"
       << "Rating: " << event.rating << "\n"
       << "Tickets Sold: " << event.ticketsSold << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Event& event) {
    std::getline(is, event.name);
    std::getline(is, event.description);
    is >> event.rating;
    is.ignore(); // Skip newline
    return is;
}