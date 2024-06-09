// source/FileHandler.cpp
#include "../header/FileHandler.h"
#include <fstream>
#include <sstream>

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
        events.push_back(parseEvent(line));
    }

    file.close();

    // Debugging: Print events read from the file
    for (const auto& event : events) {
        std::cout << "Read event: " << event.getSubject() << " on "
                  << event.getDay() << "/" << event.getMonth() << "/" << event.getYear() << std::endl;
    }

    return events;
}

Event FileHandler::parseEvent(const std::string& line) {
    std::istringstream iss(line);
    std::string startDateStr, subject;

    std::getline(iss, startDateStr, ',');
    std::getline(iss, subject, ',');

    Date startDate = Date::fromString(startDateStr);

    return Event(subject, startDate.getYear(), startDate.getMonth(), startDate.getDay());
}
