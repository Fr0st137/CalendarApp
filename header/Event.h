#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "DateFile.h"

class Event : public Date { // Event IS-A Date
public:
    Event(const std::string& subject, int year, int month, int day,
          const std::string& startTime, const std::string& endTime);

    // Getters (and potentially setters) for subject, startTime, endTime
    std::string getSubject() const;
    std::string getStartTime() const;  // Add these to the Event class
    std::string getEndTime() const;

private:
    std::string subject;
    std::string startTime; 
    std::string endTime;
};

#endif 