#include "../header/Event.h"

Event::Event(const std::string& subject, int year, int month, int day)
    : Date(year, month, day), subject(subject) {} // Constructor for Event, initializes base class Date and subject

std::string Event::getSubject() const { // Getter for the event subject
    return subject;
}
