// header/Calendar.h
#ifndef CALENDAR_H
#define CALENDAR_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Event.h"
#include "Holidays.h"
#include "DateFile.h"

class Calendar {
public:
    void addEvent(const Event& event);
    void addHoliday(const Holiday& holiday);
    void printCurrentMonth();  // New function to print the calendar for the current month

private:
    std::vector<Event> events;
    std::vector<Holiday> holidays;
    int daysInMonth(int month, int year) const;
    int getStartDay(int year, int month) const;
};

#endif // CALENDAR_H