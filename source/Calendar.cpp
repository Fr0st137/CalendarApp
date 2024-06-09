// source/Calendar.cpp
#include "../header/Calendar.h"
#include <algorithm> // Include this header for std::remove_if

void Calendar::addEvent(const Event& event) {
    events.push_back(event);
}

void Calendar::addHoliday(const Holiday& holiday) {
    holidays.push_back(holiday);
}

int Calendar::daysInMonth(int month, int year) {
    static const int daysInMonthArr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        return 29;  // February in a leap year
    }
    return daysInMonthArr[month - 1];
}

int Calendar::getStartDay(int year, int month) const {
    tm time_in = { 0, 0, 0, 1, month - 1, year - 1900 };
    time_t time_temp = mktime(&time_in);
    const tm* time_out = localtime(&time_temp);
    return time_out->tm_wday;
}

void Calendar::printCurrentMonth() {
    Date currentDate = Date::getCurrentDate();
    printMonth(currentDate.getYear(), currentDate.getMonth());
}

void Calendar::printMonth(int year, int month) {
    std::cout << "Calendar for " << month << "/" << year << std::endl;
    std::cout << "Su Mo Tu We Th Fr Sa" << std::endl;

    int startDay = this->getStartDay(year, month);
    int numDays = this->daysInMonth(month, year);

    // Print initial spaces for the first week
    for (int i = 0; i < startDay; ++i) {
        std::cout << "   ";
    }

    for (int currentDay = 1; currentDay <= numDays; ++currentDay) {
        printDay(currentDay, year, month);
        if ((startDay + currentDay) % 7 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    // Print event details
    for (int currentDay = 1; currentDay <= numDays; ++currentDay) {
        printEvents(currentDay, year, month);
    }
}

void Calendar::printDay(int day, int year, int month) {
    bool hasEvent = false;
    for (const Event& event : events) {
        if (event.getYear() == year && event.getMonth() == month && event.getDay() == day) {
            hasEvent = true;
            break;
        }
    }

    if (hasEvent) {
        std::cout << "*";
    } else {
        std::cout << " ";
    }
    std::cout << std::setw(2) << day << " ";
}

void Calendar::printEvents(int day, int year, int month) {
    bool hasEvent = false;
    for (const Event& event : events) {
        if (event.getYear() == year && event.getMonth() == month && event.getDay() == day) {
            if (!hasEvent) {
                std::cout << std::setw(2) << day << ": ";
                hasEvent = true;
            }
            std::cout << event.getSubject() << ", ";
        }
    }
    if (hasEvent) {
        std::cout << std::endl;
    }
}

void Calendar::addEventFromUser(const std::string& filename) {
    std::string subject;
    int day, month, year;

    std::cout << "Enter event subject: ";
    std::cin.ignore(); // Clear the newline left in the input buffer
    std::getline(std::cin, subject);

    std::cout << "Enter event date (dd mm yyyy): ";
    std::cin >> day >> month >> year;

    Event newEvent(subject, year, month, day);
    addEvent(newEvent);

    // Save the event to the file
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << std::setfill('0') << std::setw(2) << day << "/"
             << std::setw(2) << month << "/"
             << year << ", "
             << subject << "\n";
        file.close();
    } else {
        std::cerr << "Error: Could not open file to save the event." << std::endl;
    }
}

void Calendar::removeEventFromUser(const std::string& filename) {
    std::string subject;
    int day, month, year;

    std::cout << "Enter event subject to remove: ";
    std::cin.ignore(); // Clear the newline left in the input buffer
    std::getline(std::cin, subject);

    std::cout << "Enter event date to remove (dd mm yyyy): ";
    std::cin >> day >> month >> year;

    Event eventToRemove(subject, year, month, day);

    // Remove event from the events vector
    auto it = std::remove_if(events.begin(), events.end(),
                             [&eventToRemove](const Event& event) {
                                 return event.getSubject() == eventToRemove.getSubject() &&
                                        event.getDay() == eventToRemove.getDay() &&
                                        event.getMonth() == eventToRemove.getMonth() &&
                                        event.getYear() == eventToRemove.getYear();
                             });
    if (it != events.end()) {
        events.erase(it, events.end());
    }

    // Save the updated events list to the file
    FileHandler fileHandler(filename);
    std::vector<Event> updatedEvents = fileHandler.readEvents();

    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Start Date, Subject\n"; // Write header
        for (const auto& event : updatedEvents) {
            if (!(event.getSubject() == eventToRemove.getSubject() &&
                  event.getDay() == eventToRemove.getDay() &&
                  event.getMonth() == eventToRemove.getMonth() &&
                  event.getYear() == eventToRemove.getYear())) {
                file << std::setfill('0') << std::setw(2) << event.getDay() << "/"
                     << std::setw(2) << event.getMonth() << "/"
                     << event.getYear() << ", "
                     << event.getSubject() << "\n";
            }
        }
        file.close();
    } else {
        std::cerr << "Error: Could not open file to save the updated events." << std::endl;
    }
}
