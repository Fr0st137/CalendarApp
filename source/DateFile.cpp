#include "../header/DateFile.h"
#include <sstream>
#include <iomanip>
#include <ctime>

int currYear = 1900; 
int currMonth = 1;
int currDay = 1;

// Constructor with default values for current date
Date::Date(int year, int month, int day) {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    if (year == 1900) {
        this->year = 1900 + localTime->tm_year;
    } else {
        this->year = year;
    }
    if (month == 1) {
        this->month = 1 + localTime->tm_mon;
    } else {
        this->month = month;
    }
    if (day == 1) {
        this->day = localTime->tm_mday;
    } else {
        this->day = day;
    }
}

// ... (implementations of getters, setters, isValid, daysUntil, etc.)

// Static method to get the current date
Date Date::getCurrentDate() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    return Date(1900 + localTime->tm_year, 1 + localTime->tm_mon, localTime->tm_mday);
}

// Static method to parse a date string
Date Date::fromString(const std::string& dateStr) {
    std::istringstream iss(dateStr);
    std::string monthStr, dayStr, yearStr;

    std::getline(iss, monthStr, '/');
    std::getline(iss, dayStr, '/');
    std::getline(iss, yearStr, '/');

    int month = std::stoi(monthStr);
    int day = std::stoi(dayStr);
    int year = std::stoi(yearStr);

    return Date(year, month, day);
}

// toString method
std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << month << "/"
        << std::setw(2) << day << "/" << year;
    return oss.str();
}

// ... (implementation of isLeapYear)