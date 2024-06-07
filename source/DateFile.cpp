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
