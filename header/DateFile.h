#pragma once

#include <string>
#include <iostream>

using namespace std;

class Date {
public:
    Date(int year, int month, int day);

    // Getters and setters (consider adding validation here)
    int getYear() const;
    void setYear(int year);
    // ... similar for month and day

    // Comparison operators (>, <, ==, etc.)
    bool operator<(const Date& other) const;
    // ...

    // Other potential methods:
    bool isValid() const; // Check if date is valid
    int daysUntil(const Date& other) const; // Calculate days between dates
    std::string toString() const; // Format the date as a string

private:
    int year, month, day;
};

string monthName(int i);