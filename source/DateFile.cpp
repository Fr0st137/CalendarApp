#include <iostream>
#include <chrono>
#include <ctime>
#include "../header/DateFile.h"

using namespace std;
    // Get current time
    auto now = std::chrono::system_clock::now();
    std::time_t timeNow = std::chrono::system_clock::to_time_t(now);

    // Convert to local time
    tm* localTime = std::localtime(&timeNow);

    // Extract year, month, and day
    int currYear = 1900 + localTime->tm_year;
    int currMonth = 1 + localTime->tm_mon;  
    int currDay = localTime->tm_mday;

    // // Print the current date
    // std::cout << "Today is: " << day << "." << month << "." << year << std::endl;

string monthName(int i)
{
	switch (i)
	{
	case 1:
		return "January";
		break;

	case 2:
		return "February";
		break;

	case 3:
		return "March";
		break;

	case 4:
		return "April";
		break;

	case 5:
		return "May";
		break;

	case 6:
		return "June";
		break;

	case 7:
		return "July";
		break;

	case 8:
		return "August";
		break;

	case 9:
		return "September";
		break;

	case 10:
		return "October";
		break;

	case 11:
		return "November";
		break;

	case 12:
		return "December";
		break;

	default:
		return "";
		break;
	}
}


// Helper function to parse a date string of format "m/d/yyyy" (add to Date class)

Date Date::fromString(const std::string& dateStr) {
    std::istringstream iss(dateStr);
    std::string monthStr, dayStr, yearStr;

    std::getline(iss, monthStr, '/');
    std::getline(iss, dayStr, '/');
    std::getline(iss, yearStr, '/');

    int month = std::stoi(monthStr);
    int day = std::stoi(dayStr);
    int year = std::stoi(yearStr);

    return Date(year, month, day);
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << month << "/"
        << std::setw(2) << day << "/" << year;
    return oss.str();
}