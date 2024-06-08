#ifndef DATEFILE_H // Unique identifier for your header
#define DATEFILE_H

#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class Date {
public:
    Date(int year, int month, int day);

    // Getters 
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

    // ... (other methods, like operators, isValid(), etc.)

    // fromString method to parse date from a string
    static Date fromString(const std::string& dateStr);  // Declaration ONLY
    std::string toString() const;  // Declaration of toString() method
private:
    int year, month, day;
};


#endif // DATEFILE_H