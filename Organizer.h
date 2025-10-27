// TO DO: #include all the standard libraries and your own libraries here
#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <string>
#include <iostream>
#include <vector>

#include "LinkedBag.h"

#include "Event.h"
Event::Event() : name(""), description(""), rating(0.0), ticketsSold(0) {}


Event::Event(const std::string& n, const std::string& d, double r)
    : name(n), description(d), rating(r), ticketsSold(0) {}


Event::~Event() {}

std::string Event::getName() const { return name; }
std::string Event::getDescription() const { return description; }
double Event::getRating() const { return rating; }
int Event::getTicketsSold() const { return ticketsSold; }


void Event::setName(const std::string& n) { name = n; }
void Event::setDescription(const std::string& d) { description = d; }
void Event::setRating(double r) { rating = r; }


void Event::display(std::ostream& os) const {
    os << "Name: " << name << "\n"
       << "Description: " << description << "\n"
       << "Rating: " << rating << "\n"
       << "Tickets Sold: " << ticketsSold << "\n";
}


// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Event::operator==(const Event& otherEvent) const {
	return Event::name == otherEvent.name;
}




