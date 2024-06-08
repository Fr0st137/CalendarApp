#pragma once

#include "DateFile.h"

class Holiday : public Date { // Holiday IS-A Date
public:
    Holiday(const std::string& name, int year, int month, int day);

    // Getters for name
    std::string getName() const;
private:
    std::string name;
};


void showHolidays();