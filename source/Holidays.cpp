#include "../header/Holidays.h"

Holiday::Holiday(const std::string& name, int year, int month, int day)
    : Date(year, month, day), name(name) {} // Constructor for Holiday, initializes base class Date and name

std::string Holiday::getName() const { // Getter for the holiday name
    return name;
}
