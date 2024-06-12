// File: header/Holidays.h

#ifndef HOLIDAY_H
#define HOLIDAY_H

#include "DateFile.h"  // Include Date class header

class Holiday : public Date {
public:
    Holiday(const std::string& name, int year, int month, int day); // Constructor for Holiday

    std::string getName() const;  // Getter for the holiday name

private:
    std::string name;  // Name of the holiday
};

#endif // HOLIDAY_H
