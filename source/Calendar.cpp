// File: source/Calendar.cpp

#include "../header/Calendar.h"
#include <algorithm>  // For using std::remove_if
#include <iomanip>    // For manipulating the output of C++ streams
#include <iostream>   // For input and output stream
#include <fstream>    // For file stream
#include <map>        // For using std::map
#include <sstream>    // For string stream
#include <string>     // For using std::string

// Define color codes for terminal output
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string ORANGE = "\033[33m";
const std::string RESET = "\033[0m";

void Calendar::addEvent(const Event& event) {
    events.push_back(event); // Add an event to the events vector
}

void Calendar::addHoliday(const Holiday& holiday) {
    holidays.push_back(holiday); // Add a holiday to the holidays vector
}

int Calendar::daysInMonth(int month, int year) {
    static const int daysInMonthArr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        return 29; // February in a leap year
    }
    return daysInMonthArr[month - 1]; // Return days in the given month
}

int Calendar::getStartDay(int year, int month) const {
    tm time_in = { 0, 0, 0, 1, month - 1, year - 1900 };
    time_t time_temp = mktime(&time_in);
    const tm* time_out = localtime(&time_temp);
    return time_out->tm_wday; // Get the start day of the month
}

void Calendar::printCurrentMonth() {
    Date currentDate = Date::getCurrentDate();
    printMonth(currentDate.getYear(), currentDate.getMonth());
    showHolidaysForMonth(currentDate.getYear(), currentDate.getMonth()); // Print current month and holidays
}

void Calendar::printMonth(int year, int month) {
    std::cout << "Calendar for " << std::setfill('0') << std::setw(2) << month << "/" << year << std::endl;
    std::cout << "Su Mo Tu We Th Fr Sa" << std::endl;

    int startDay = this->getStartDay(year, month);
    int numDays = this->daysInMonth(month, year);

    for (int i = 0; i < startDay; ++i) {
        std::cout << "   "; // Print spaces for the start day
    }

    for (int currentDay = 1; currentDay <= numDays; ++currentDay) {
        bool hasEvent = false;
        bool hasHoliday = false;

        for (const Event& event : events) {
            if (event.getYear() == year && event.getMonth() == month && event.getDay() == currentDay) {
                hasEvent = true;
                break; // Check if the current day has an event
            }
        }

        for (const Holiday& holiday : holidays) {
            if (holiday.getYear() == year && holiday.getMonth() == month && holiday.getDay() == currentDay) {
                hasHoliday = true;
                break; // Check if the current day has a holiday
            }
        }

        if (hasEvent && hasHoliday) {
            std::cout << ORANGE << std::setw(2) << std::setfill('0') << currentDay << RESET << " ";
        } else if (hasEvent) {
            std::cout << GREEN << std::setw(2) << std::setfill('0') << currentDay << RESET << " ";
        } else if (hasHoliday) {
            std::cout << RED << std::setw(2) << std::setfill('0') << currentDay << RESET << " ";
        } else {
            std::cout << std::setw(2) << std::setfill('0') << currentDay << " ";
        }
        
        if ((startDay + currentDay) % 7 == 0) {
            std::cout << std::endl; // Print a new line after every week
        }
    }
    std::cout << std::endl;

    for (int currentDay = 1; currentDay <= numDays; ++currentDay) {
        printEvents(currentDay, year, month); // Print events for each day
    }
}

void Calendar::printMonthByName(int year, const std::string& monthName) {
    static const std::map<std::string, int> monthMap = {
        {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4}, {"May", 5}, {"June", 6},
        {"July", 7}, {"August", 8}, {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
    };

    auto it = monthMap.find(monthName);
    if (it != monthMap.end()) {
        printMonth(year, it->second);
        showHolidaysForMonth(year, it->second); // Print the specified month and holidays
    } else {
        std::cerr << "Invalid month name: " << monthName << std::endl; // Error if month name is invalid
    }
}

void Calendar::printDay(int day, int year, int month) {
    bool hasEvent = false;
    bool hasHoliday = false;

    for (const Event& event : events) {
        if (event.getYear() == year && event.getMonth() == month && event.getDay() == day) {
            hasEvent = true;
            break; // Check if the day has an event
        }
    }

    for (const Holiday& holiday : holidays) {
        if (holiday.getYear() == year && holiday.getMonth() == month && holiday.getDay() == day) {
            hasHoliday = true;
            break; // Check if the day has a holiday
        }
    }

    if (hasEvent && hasHoliday) {
        std::cout << ORANGE << std::setw(2) << std::setfill('0') << day << RESET << " ";
    } else if (hasEvent) {
        std::cout << GREEN << std::setw(2) << std::setfill('0') << day << RESET << " ";
    } else if (hasHoliday) {
        std::cout << RED << std::setw(2) << std::setfill('0') << day << RESET << " ";
    } else {
        std::cout << std::setw(2) << std::setfill('0') << day << " ";
    }
}

void Calendar::printEvents(int day, int year, int month) {
    bool hasEvent = false;

    for (const Event& event : events) {
        if (event.getYear() == year && event.getMonth() == month && event.getDay() == day) {
            if (!hasEvent) {
                std::cout << std::setw(2) << std::setfill('0') << day << "/"
                          << std::setw(2) << std::setfill('0') << month << "/"
                          << year << ": ";
                hasEvent = true;
            }
            std::cout << event.getSubject() << ", ";
        }
    }
    if (hasEvent) {
        std::cout << std::endl; // Print events for a specific day
    }
}

void Calendar::showHolidays() {
    std::cout << "Start Date,Subject" << std::endl;
    for (const Holiday& holiday : holidays) {
        std::cout << std::setfill('0') << std::setw(2) << holiday.getDay() << "/"
                  << std::setfill('0') << std::setw(2) << holiday.getMonth() << "/"
                  << holiday.getYear() << ","
                  << holiday.getName() << std::endl; // Display all holidays
    }
}

void Calendar::showHolidaysForMonth(int year, int month) {
    std::cout << "Holidays for " << std::setfill('0') << std::setw(2) << month << "/" << year << ":" << std::endl;
    for (const Holiday& holiday : holidays) {
        if (holiday.getYear() == year && holiday.getMonth() == month) {
            std::cout << std::setfill('0') << std::setw(2) << holiday.getDay() << "/"
                      << std::setfill('0') << std::setw(2) << holiday.getMonth() << "/"
                      << holiday.getYear() << " - "
                      << holiday.getName() << std::endl; // Display holidays for a specific month
        }
    }
}

bool Calendar::getDateFromUser(Date& date) {
    std::string dateStr;
    std::cout << "Enter date (dd/mm/yyyy): ";
    std::cin >> dateStr;

    if (!Date::isValidDateFormat(dateStr)) {
        std::cerr << "Error: Invalid date format. Please use dd/mm/yyyy format." << std::endl;
        return false; // Validate date format
    }

    Date tempDate = Date::fromString(dateStr);
    if (!tempDate.isValid()) {
        std::cerr << "Error: Invalid date. Please enter a valid date." << std::endl;
        return false; // Check if the date is valid
    }

    date = tempDate;
    return true; // Get date from user input
}

void Calendar::addEventFromUser(const std::string& filename) {
    std::string subject;
    Date eventDate;

    std::cout << "Enter event subject: ";
    std::cin.ignore();
    std::getline(std::cin, subject);

    if (!getDateFromUser(eventDate)) {
        return; // Add event from user input
    }

    Event newEvent(subject, eventDate.getYear(), eventDate.getMonth(), eventDate.getDay());
    addEvent(newEvent);

    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << std::setfill('0') << std::setw(2) << eventDate.getDay() << "/"
             << std::setfill('0') << std::setw(2) << eventDate.getMonth() << "/"
             << eventDate.getYear() << ","
             << subject << "\n";
        file.close();
    } else {
        std::cerr << "Error: Could not open file to save the event." << std::endl; // Save event to file
    }
}

// Helper function to trim leading and trailing spaces
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

void Calendar::removeEventFromUser(const std::string& filename) {
    std::string subject;
    std::cout << "Enter event subject to remove: ";
    std::cin.ignore();
    std::getline(std::cin, subject);
    subject = trim(subject);

    auto it = std::remove_if(events.begin(), events.end(),
                             [&subject](const Event& event) {
                                 return trim(event.getSubject()) == subject;
                             });

    if (it != events.end()) {
        events.erase(it, events.end());
    } else {
        std::cerr << "Event not found." << std::endl;
        return; // Remove event based on user input
    }

    // Update the EventLog.csv file
    std::vector<Event> updatedEvents;
    std::ifstream file_in(filename);
    std::string line;
    if (file_in.is_open()) {
        while (std::getline(file_in, line)) {
            std::istringstream iss(line);
            std::string dateStr, eventSubject;
            std::getline(iss, dateStr, ',');
            std::getline(iss, eventSubject, ',');

            if (dateStr.empty() || eventSubject.empty()) continue;

            if (trim(eventSubject) != subject) {
                Date date = Date::fromString(dateStr);
                updatedEvents.push_back(Event(eventSubject, date.getYear(), date.getMonth(), date.getDay()));
            }
        }
        file_in.close();
    } else {
        std::cerr << "Error: Could not open file to read the events." << std::endl;
        return;
    }

    std::ofstream file_out(filename);
    if (file_out.is_open()) {
        for (const auto& event : updatedEvents) {
            file_out << std::setfill('0') << std::setw(2) << event.getDay() << "/"
                     << std::setfill('0') << std::setw(2) << event.getMonth() << "/"
                     << event.getYear() << ","
                     << event.getSubject() << "\n";
        }
        file_out.close();
    } else {
        std::cerr << "Error: Could not open file to save the updated events." << std::endl;
        return; // Update the events file after removal
    }
}

void Calendar::showAllEvents(int year) {
    for (int month = 1; month <= 12; ++month) {
        for (int day = 1; day <= daysInMonth(month, year); ++day) {
            printEvents(day, year, month); // Show all events for a specific year
        }
    }
}
