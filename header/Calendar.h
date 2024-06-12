// File: header/Calendar.h

#ifndef CALENDAR_H
#define CALENDAR_H

#include <vector>        // For using std::vector
#include <iostream>      // For input and output stream
#include <iomanip>       // For manipulating the output of C++ streams
#include <ctime>         // For handling date and time
#include "Event.h"       // Include Event class header
#include "Holidays.h"    // Include Holidays class header
#include "DateFile.h"    // Include DateFile class header
#include "FileHandler.h" // Include FileHandler class header

class Calendar {
public:
    void addEvent(const Event& event);           // Method to add an event to the calendar
    void addHoliday(const Holiday& holiday);     // Method to add a holiday to the calendar
    void printCurrentMonth();                    // Method to print the current month
    void printMonth(int year, int month);        // Method to print a specific month
    void printMonthByName(int year, const std::string& monthName); // Method to print a specific month by its name
    void addEventFromUser(const std::string& filename);  // Method to add an event from user input
    void removeEventFromUser(const std::string& filename);  // Method to remove an event based on user input
    void showHolidays();                         // Method to display all holidays
    void showAllEvents(int year);                // Method to display all events for a specific year
    void showHolidaysForMonth(int year, int month); // Method to display holidays for a specific month

    static int daysInMonth(int month, int year); // Static method to get the number of days in a month
    void printEvents(int day, int year, int month); // Method to print events for a specific day

private:
    std::vector<Event> events;                   // Vector to store events
    std::vector<Holiday> holidays;               // Vector to store holidays
    int getStartDay(int year, int month) const;  // Method to get the start day of the month
    void printDay(int day, int year, int month); // Method to print a specific day
    bool getDateFromUser(Date& date);            // Method to get date from user
};

#endif // CALENDAR_H
