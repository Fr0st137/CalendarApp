// header/FileHandler.h
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "DateFile.h"
#include "Event.h"

class FileHandler {
public:
    FileHandler(const std::string& filename);
    std::vector<Event> readEvents();

private:
    std::string filename;
    Event parseEvent(const std::string& line);
};

#endif // FILEHANDLER_H