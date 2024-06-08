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

