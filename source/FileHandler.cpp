// File: source/FileHandler.cpp

#include "../header/FileHandler.h"
#include <iomanip>  // For manipulating the output of C++ streams

FileHandler::FileHandler(const std::string& filename) : filename(filename) {}

std::vector<Event> FileHandler::readEvents() {
    std::ifstream file(filename);
    std::string line;

    std::vector<Event> events;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return events; // Read events from file
    }

    std::getline(file, line); // Skip the header row

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        events.push_back(parseEvent(line));
    }

    file.close();
    return events;
}

std::vector<Holiday> FileHandler::readHolidays() {
    std::ifstream file(filename);
    std::string line;
    std::vector<Holiday> holidays;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return holidays; // Read holidays from file
    }

    std::getline(file, line); // Skip the header row

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        holidays.push_back(parseHoliday(line));
    }

    file.close();
    return holidays;
}

Event FileHandler::parseEvent(const std::string& line) {
    std::istringstream iss(line);
    std::string startDateStr, subject;

    std::getline(iss, startDateStr, ',');
    std::getline(iss, subject, ',');

    Date startDate = Date::fromString(startDateStr);
    return Event(subject, startDate.getYear(), startDate.getMonth(), startDate.getDay()); // Parse event from string line
}

Holiday FileHandler::parseHoliday(const std::string& line) {
    std::istringstream iss(line);
    std::string dateStr, name;

    std::getline(iss, dateStr, ',');
    std::getline(iss, name);

    Date startDate = Date::fromString(dateStr);
    return Holiday(name, startDate.getYear(), startDate.getMonth(), startDate.getDay()); // Parse holiday from string line
}
