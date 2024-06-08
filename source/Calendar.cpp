// source/Calendar.cpp
#include "../header/Calendar.h"

void Calendar::addEvent(const Event& event) {
    events.push_back(event);
}

void Calendar::addHoliday(const Holiday& holiday) {
    holidays.push_back(holiday);
}

int Calendar::daysInMonth(int month, int year) const {
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        return 29;  // February in a leap year
    }
    return daysInMonth[month - 1];
}

int Calendar::getStartDay(int year, int month) const {
    tm time_in = { 0, 0, 0, 1, month - 1, year - 1900 };
    time_t time_temp = mktime(&time_in);
    const tm* time_out = localtime(&time_temp);
    return time_out->tm_wday;
}

void Calendar::printCurrentMonth() {
    Date currentDate = Date::getCurrentDate();
    int year = currentDate.getYear();
    int month = currentDate.getMonth();

    std::cout << "Calendar for " << month << "/" << year << std::endl;
    std::cout << "Su Mo Tu We Th Fr Sa" << std::endl;

    int startDay = getStartDay(year, month);
    int numDays = daysInMonth(month, year);

    int currentDay = 1;

    for (int i = 0; i < startDay; ++i) {
        std::cout << "   ";
    }

    for (int i = startDay; i < 7; ++i) {
        std::cout << std::setw(2) << currentDay++ << " ";
    }
    std::cout << std::endl;

    while (currentDay <= numDays) {
        for (int i = 0; i < 7 && currentDay <= numDays; ++i) {
            std::cout << std::setw(2) << currentDay++ << " ";
        }
        std::cout << std::endl;
    }
}