#include "../header/FileHandler.h"
#include <sstream>
#include <algorithm> // For std::replace

FileHandler::FileHandler(const std::string& filename) : filename(filename) {}

std::vector<Event> FileHandler::readEvents() {
    std::ifstream file(filename);
    std::string line;
    std::vector<Event> events;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return events;
    }

    // Skip header row
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string startDateStr, endDateStr, startTime, endTime, subject;

        std::getline(iss, startDateStr, ',');
        std::getline(iss, endDateStr, ',');
        std::getline(iss, startTime, ',');
        std::getline(iss, endTime, ',');
        std::getline(iss, subject, ',');

        // Convert date strings to Date objects (assuming you have a Date::fromString() method)
        Date startDate = Date::fromString(startDateStr);
        Date endDate = Date::fromString(endDateStr);

        events.push_back(Event(subject, startDate.getYear(), startDate.getMonth(), startDate.getDay(),
                                    startTime, endTime));
    }

    file.close();
    return events;
}

