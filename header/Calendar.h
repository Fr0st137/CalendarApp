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
#include "FileHandler.h"

class Calendar {
public:
    void addEvent(const Event& event);
    void addHoliday(const Holiday& holiday);
    void printCurrentMonth();
    void printMonth(int year, int month);
    void addEventFromUser(const std::string& filename);
    void removeEventFromUser(const std::string& filename); // New method to remove event from user

    static int daysInMonth(int month, int year);

private:
    std::vector<Event> events;
    std::vector<Holiday> holidays;
    int getStartDay(int year, int month) const;
    void printDay(int day, int year, int month);
    void printEvents(int day, int year, int month);
};

#endif // CALENDAR_H
