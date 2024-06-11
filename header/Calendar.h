// File: header/Calendar.h

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
    void printMonthByName(int year, const std::string& monthName);
    void addEventFromUser(const std::string& filename);
    void removeEventFromUser(const std::string& filename);
    void showHolidays();
    void showAllEvents(int year);
    void showHolidaysForMonth(int year, int month);

    static int daysInMonth(int month, int year);
    void printEvents(int day, int year, int month);

private:
    std::vector<Event> events;
    std::vector<Holiday> holidays;
    int getStartDay(int year, int month) const;
    void printDay(int day, int year, int month);
    bool getDateFromUser(Date& date);
};

#endif // CALENDAR_H