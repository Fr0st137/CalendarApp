#include "../header/Event.h"

Event::Event(const std::string& subject, int year, int month, int day)
    : Date(year, month, day), subject(subject) {}

std::string Event::getSubject() const {
    return subject;
}
