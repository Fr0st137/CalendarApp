// File: header/FileHandler.h
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "DateFile.h"
#include "Event.h"
#include "Holidays.h"

class FileHandler {
public:
    FileHandler(const std::string& filename);
    std::vector<Event> readEvents();
    std::vector<Holiday> readHolidays();

private:
    std::string filename;
    Event parseEvent(const std::string& line);
    Holiday parseHoliday(const std::string& line);
};

#endif // FILEHANDLER_H