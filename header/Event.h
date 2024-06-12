// File: header/Event.h

#ifndef EVENT_H
#define EVENT_H

#include <string>   // For using std::string
#include "DateFile.h"  // Include Date class header

class Event : public Date {
public:
    Event(const std::string& subject, int year, int month, int day); // Constructor for Event

    std::string getSubject() const;  // Getter for the event subject

private:
    std::string subject;  // Subject of the event
};

#endif // EVENT_H
