
#include <vector>
#include "Event.h"
#include "Holidays.h"

class Calendar {
public:
    void addEvent(const Event& event);
    void addHoliday(const Holiday& holiday);
    // ... methods to get events/holidays for a date, print calendar views, etc.

private:
    std::vector<Event> events;
    std::vector<Holiday> holidays;
};