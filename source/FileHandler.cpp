// File: source/FileHandler.cpp

#include "../header/FileHandler.h"
#include <iomanip>

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
    return events;
}

std::vector<Holiday> FileHandler::readHolidays() {
    std::ifstream file(filename);
    std::string line;
    std::vector<Holiday> holidays;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return holidays;
    }

    // Skip header row
    std::getline(file, line);

    while (std::getline(file, line)) {
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

    return Event(subject, startDate.getYear(), startDate.getMonth(), startDate.getDay());
}

Holiday FileHandler::parseHoliday(const std::string& line) {
    std::istringstream iss(line);
    std::string dateStr, name;

    std::getline(iss, dateStr, ','); // Read until the comma
    std::getline(iss, name);         // Read the rest of the line (holiday name)

    Date startDate = Date::fromString(dateStr);

    // Ensure the date is formatted as dd/mm/yyyy
    std::ostringstream formattedDate;
    formattedDate << std::setfill('0') << std::setw(2) << startDate.getDay() << "/"
                  << std::setfill('0') << std::setw(2) << startDate.getMonth() << "/"
                  << startDate.getYear();

    return Holiday(name, startDate.getYear(), startDate.getMonth(), startDate.getDay());
}
