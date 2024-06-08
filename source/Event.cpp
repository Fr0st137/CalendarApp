#include "../header/Event.h"

Event::Event(const std::string& subject, int year, int month, int day,
        const std::string& startTime, const std::string& endTime) 
    : Date(year, month, day), subject(subject), startTime(startTime), endTime(endTime) {}

// ... other Event member function definitions
std::string Event::getEndTime() const {
    return endTime;
}

std::string Event::getStartTime() const {
    return startTime;
}

std::string Event::getSubject() const {
    return subject;
}