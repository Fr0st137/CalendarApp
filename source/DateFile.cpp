// File: source/DateFile.cpp

#include "../header/DateFile.h"
#include <iomanip>    // For manipulating the output of C++ streams
#include <ctime>      // For handling date and time
#include <sstream>    // For string stream
#include <regex>      // For regex operations
#include <iostream>   // For input and output stream

Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day; // Constructor implementation
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day; // Comparison operator
}

bool Date::isValid() const {
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > daysInMonth(month, year)) return false;
    return true; // Check if date is valid
}

int Date::daysUntil(const Date& other) const {
    tm thisDate = {0, 0, 0, day, month - 1, year - 1900};
    tm otherDate = {0, 0, 0, other.day, other.month - 1, other.year - 1900};
    time_t thisTime = mktime(&thisDate);
    time_t otherTime = mktime(&otherDate);
    return static_cast<int>(difftime(otherTime, thisTime) / (60 * 60 * 24)); // Calculate days until another date
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << day << "/"
        << std::setfill('0') << std::setw(2) << month << "/" << year;
    return oss.str(); // Convert date to string
}

Date Date::fromString(const std::string& dateStr) {
    std::istringstream iss(dateStr);
    std::string dayStr, monthStr, yearStr;

    std::getline(iss, dayStr, '/');
    std::getline(iss, monthStr, '/');
    std::getline(iss, yearStr, '/');

    if (dayStr.empty() || monthStr.empty() || yearStr.empty()) {
        std::cerr << "Error: Invalid date string format in fromString: " << dateStr << std::endl;
        return Date(); // Return a default date
    }

    try {
        int day = std::stoi(dayStr);
        int month = std::stoi(monthStr);
        int year = std::stoi(yearStr);

        return Date(year, month, day); // Convert string to date
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid date string format in fromString: " << dateStr << std::endl;
        return Date(); // Return a default date
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Date string out of range in fromString: " << dateStr << std::endl;
        return Date(); // Return a default date
    }
}

Date Date::getCurrentDate() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    return Date(1900 + localTime->tm_year, 1 + localTime->tm_mon, localTime->tm_mday); // Get the current date
}

bool Date::isLeapYear(int year) {
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    return year % 400 == 0; // Check if the year is a leap year
}

bool Date::isValidDateFormat(const std::string& dateStr) {
    std::regex datePattern(R"(\b\d{2}/\d{2}/\d{4}\b)");
    return std::regex_match(dateStr, datePattern); // Validate date format using regex
}

int Date::daysInMonth(int month, int year) {
    static const int daysInMonthArr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonthArr[month - 1]; // Return days in the given month
}
