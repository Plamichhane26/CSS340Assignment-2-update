#ifndef VIRTUAL_EVENT_H
#define VIRTUAL_EVENT_H

#include "Event.h"
#include <string>
#include <memory>

class VirtualEvent : public Event {
private:
    std::string virtualVenue;
    std::string audience;

public:
    // Constructors and destructor (BIG 3)
    VirtualEvent();
    VirtualEvent(const std::string& n,
                const std::string& d,
                double r,
                const std::string& vvenue,
                const std::string& aud);
    VirtualEvent(const VirtualEvent& other);  // Copy constructor
    ~VirtualEvent() override = default;

    // Assignment operator (BIG 3)
    VirtualEvent& operator=(const VirtualEvent& other);

    // Implement pure virtual functions
    std::string sellTicket(int quantity) override;
    void display(std::ostream& os = std::cout) const override;
    
    // Clone implementation
    std::shared_ptr<Event> clone() const override {
        return std::make_shared<VirtualEvent>(*this);
    }

    // Additional operator overloads
    bool operator==(const VirtualEvent& other) const;
    friend std::ostream& operator<<(std::ostream& os, const VirtualEvent& event);
};

#endif
