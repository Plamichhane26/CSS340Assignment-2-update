

#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>
#include <memory>

class Event {
protected:
    std::string name;
    std::string description;
    double      rating;
    int         ticketsSold;

public:
    // Constructors and destructor
    Event();
    Event(const std::string& n, const std::string& d, double r);
    Event(const Event& other);  // Copy constructor
    virtual ~Event();

    // Assignment operator
    Event& operator=(const Event& other);

    // Comparison operators
    bool operator==(const Event& otherEvent) const;
    bool operator!=(const Event& otherEvent) const;
    bool operator<(const Event& otherEvent) const;
    bool operator>(const Event& otherEvent) const;

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    double getRating() const;
    int getTicketsSold() const;

    // Setters
    void setName(const std::string& n);
    void setDescription(const std::string& d);
    void setRating(double r);

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const Event& event);
    friend std::istream& operator>>(std::istream& is, Event& event);

    // Abstract interface
    virtual std::string sellTicket(int quantity) = 0;
    virtual void display(std::ostream& os = std::cout) const;
    
    // Clone method for proper copying of derived classes
    virtual std::shared_ptr<Event> clone() const = 0;
};

#endif




