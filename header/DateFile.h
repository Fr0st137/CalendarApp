// header/DateFile.h
#ifndef DATEFILE_H
#define DATEFILE_H

#include <string>
#include <regex>

class Date {
public:
    Date(int year = 1900, int month = 1, int day = 1);
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    bool operator<(const Date& other) const;
    bool isValid() const;
    int daysUntil(const Date& other) const;
    std::string toString() const;
    static Date getCurrentDate();
    static Date fromString(const std::string& dateStr);
    static int daysInMonth(int month, int year);
    static bool isValidDateFormat(const std::string& dateStr);

private:
    int year;
    int month;
    int day;
    bool isLeapYear(int year) const;
};

extern int currYear;
extern int currMonth;
extern int currDay;

#endif // DATEFILE_H