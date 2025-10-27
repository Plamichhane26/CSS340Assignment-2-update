// TO DO: #include needed standard libraries and your own libraries here
#include "Organizer.h"
#include "Event.h"
#include <iostream>
#include <vector>

// TO DO: function implementations

bool Organizer::operator==(const Organizer& otherOrganizer) const {
    return (Organizer::username == otherOrganizer.username) &&
           (Organizer::email == otherOrganizer.email);
}

void Organizer::displayProfile(std::ostream& os) const {
    os << "Username: " << username << "\n"
       << "Email: " << email << "\n"
       << "Bio: " << bio << "\n"
       << "Profile Picture: " << profilePicture << "\n";
}

void Organizer::setPassword(const std::string& newPw) {
    password = newPw;
}

int Organizer::getEventsSize() const {
    return events.getCurrentSize();
}

bool Organizer::addEventReverseK(Event* ev, int kFromEnd) {
    return events.reverseAppendK(ev, kFromEnd);
}

Event* Organizer::getKthEvent(int k) const {
    Node<Event*>* node = events.findKthItem(k);
    return node ? node->getItem() : nullptr;
}

bool Organizer::removeEventByName(const std::string& targetName) {
    std::vector<Event*> v = events.toVector();
    Event* found = nullptr;
    for (Event* e : v) {
        if (e && e->getName() == targetName) { found = e; break; }
    }
    if (!found) return false;
    bool ok = events.remove(found);
    if (ok) delete found;   // free memory after removing from bag
    return ok;
}


void Organizer::displayAllEvents(std::ostream& os) const {
    std::vector<Event*> v = events.toVector();
    if (v.empty()) {
        os << "No events yet.\n";
        return;
    }
    for (size_t i = 0; i < v.size(); ++i) {
        os << "[" << i << "]\n";
        if (v[i]) v[i]->display(os);
        os << "-------------------------\n";
    }
}
// Operator == overloading implementation

