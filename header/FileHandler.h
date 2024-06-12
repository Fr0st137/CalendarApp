// File: header/FileHandler.h

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>    // For input and output stream
#include <fstream>     // For file stream
#include <string>      // For using std::string
#include <vector>      // For using std::vector
#include <sstream>     // For string stream
#include "DateFile.h"  // Include Date class header
#include "Event.h"     // Include Event class header
#include "Holidays.h"  // Include Holiday class header

class FileHandler {
public:
    FileHandler(const std::string& filename);         // Constructor for FileHandler
    std::vector<Event> readEvents();                  // Method to read events from file
    std::vector<Holiday> readHolidays();              // Method to read holidays from file

private:
    std::string filename;                             // Filename to read from
    Event parseEvent(const std::string& line);        // Method to parse event from string line
    Holiday parseHoliday(const std::string& line);    // Method to parse holiday from string line
};

#endif // FILEHANDLER_H
