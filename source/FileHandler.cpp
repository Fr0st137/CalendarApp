#include "../header/FileHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct FileEntry {
    int index;
    std::string name;
    std::string date;
    double hours;
    std::string optionalDescription;
};

std::vector<FileEntry> readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<FileEntry> entries;

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return entries; // Return an empty vector on error
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        FileEntry entry;

        if (ss >> entry.index >> entry.name >> entry.date >> entry.hours) {
            std::getline(ss, entry.optionalDescription); // Read the rest as description
            entries.push_back(entry);
        } else {
            std::cerr << "Warning: Invalid line format: " << line << std::endl;
        }
    }

    file.close();
    return entries;
}

std::string filename = "../EventLog.txt"; 
std::vector<FileEntry> data = readFromFile(filename);
