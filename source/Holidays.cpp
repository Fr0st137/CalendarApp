#include "../header/Holidays.h"

Holiday::Holiday(const std::string& name, int year, int month, int day)
    : Date(year, month, day), name(name) {}

std::string Holiday::getName() const {
    return name;
}
