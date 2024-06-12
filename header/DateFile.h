// File: header/DateFile.h

#ifndef DATEFILE_H
#define DATEFILE_H

#include <string>   // For using std::string
#include <regex>    // For using std::regex

class Date {
public:
    Date(int year = 1900, int month = 1, int day = 1);  // Constructor with default values
    int getYear() const { return year; }                // Getter for year
    int getMonth() const { return month; }              // Getter for month
    int getDay() const { return day; }                  // Getter for day
    void setYear(int year);                             // Setter for year
    void setMonth(int month);                           // Setter for month
    void setDay(int day);                               // Setter for day
    bool operator<(const Date& other) const;            // Operator overloading for comparison
    bool isValid() const;                               // Method to check if date is valid
    int daysUntil(const Date& other) const;             // Method to calculate days until another date
    std::string toString() const;                       // Method to convert date to string
    static Date getCurrentDate();                       // Static method to get current date
    static Date fromString(const std::string& dateStr); // Static method to create date from string
    static int daysInMonth(int month, int year);        // Static method to get days in a month
    static bool isValidDateFormat(const std::string& dateStr); // Static method to validate date format
    static bool isLeapYear(int year);                   // Static method to check if year is leap

private:
    int year;                                           // Year of the date
    int month;                                          // Month of the date
    int day;                                            // Day of the date
};

#endif // DATEFILE_H
