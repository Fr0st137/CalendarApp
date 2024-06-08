#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "DateFile.h"
#include "Holidays.h"
#include "Event.h"



class FileHandler {
public:
    FileHandler(const std::string& filename); 
    std::vector<Event> readEvents();
    std::vector<Holiday> readHolidays(); // If needed

private:
    std::string filename; // Store the filename
    // Helper functions for parsing events/holidays from file
    Event parseEvent(const std::string& line); 
    Holiday parseHoliday(const std::string& line);
};
#endif 