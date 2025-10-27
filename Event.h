

#ifndef EVENT_H
#define EVENT_H

// TO DO: #include all the standard libraries and your own libraries here
#include <string>
#include <iostream>

// To DO: define the class Event with the necessary functions' prototypes and data fields
class Event {
protected:
    std::string name;
    std::string description;
    double      rating;
    int         ticketsSold;

public:
    Event();
    Event(const std::string& n, const std::string& d, double r);
    virtual ~Event();

    std::string getName()        const;
    std::string getDescription() const;
    double      getRating()      const;
    int         getTicketsSold() const;

    void setName(const std::string& n);
    void setDescription(const std::string& d);
    void setRating(double r);

    // Compare events by name
    bool operator==(const Event& otherEvent) const;

    // Abstract interface
    virtual std::string sellTicket(int quantity) = 0;
    virtual void display(std::ostream& os = std::cout) const;
};
#endif




