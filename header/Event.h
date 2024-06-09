// header/Event.h
#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "DateFile.h"

class Event : public Date {
public:
    Event(const std::string& subject, int year, int month, int day);

    std::string getSubject() const;

private:
    std::string subject;
};

#endif // EVENT_H