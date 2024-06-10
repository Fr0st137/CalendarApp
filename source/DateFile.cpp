#include "../header/DateFile.h"
#include "../header/Calendar.h"
#include <iomanip>
#include <ctime>
#include <sstream>
#include <regex>

int currYear = 1900;
int currMonth = 1;
int currDay = 1;

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

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::isValid() const {
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > Calendar::daysInMonth(month, year)) return false;
    return true;
}

int Date::daysUntil(const Date& other) const {
    tm thisDate = { 0, 0, 0, day, month - 1, year - 1900 };
    tm otherDate = { 0, 0, 0, other.day, other.month - 1, other.year - 1900 };
    time_t thisTime = mktime(&thisDate);
    time_t otherTime = mktime(&otherDate);
    return static_cast<int>(difftime(otherTime, thisTime) / (60 * 60 * 24));
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << day << "/"
        << std::setw(2) << month << "/" << year;
    return oss.str();
}

Date Date::fromString(const std::string& dateStr) {
    std::istringstream iss(dateStr);
    std::string dayStr, monthStr, yearStr;

    std::getline(iss, dayStr, '/');
    std::getline(iss, monthStr, '/');
    std::getline(iss, yearStr, '/');

    int day = std::stoi(dayStr);
    int month = std::stoi(monthStr);
    int year = std::stoi(yearStr);

    return Date(year, month, day);
}

Date Date::getCurrentDate() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    return Date(1900 + localTime->tm_year, 1 + localTime->tm_mon, localTime->tm_mday);
}

bool Date::isLeapYear(int year) const {
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    return year % 400 == 0;
}

bool Date::isValidDateFormat(const std::string& dateStr) {
    std::regex datePattern(R"(\b\d{2}/\d{2}/\d{4}\b)");
    return std::regex_match(dateStr, datePattern);
}
