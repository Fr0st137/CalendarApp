#ifndef HOLIDAY_H
#define HOLIDAY_H

#include "DateFile.h"

class Holiday : public Date { // Holiday IS-A Date
public:
    Holiday(const std::string& name, int year, int month, int day);

    std::string getName() const;
private:
    std::string name;
};

#endif // HOLIDAY_H
