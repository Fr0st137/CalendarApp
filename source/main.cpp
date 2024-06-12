// File: source/main.cpp

#include <iostream>    // For input and output stream
#include <chrono>      // For time-related functions
#include <ctime>       // For handling date and time
#include <iomanip>     // For manipulating the output of C++ streams
#include <limits>      // For numeric limits
#include "../header/Calendar.h"  // Include Calendar class header
#include "../header/DateFile.h"  // Include Date class header
#include "../header/Event.h"     // Include Event class header
#include "../header/FileHandler.h" // Include FileHandler class header
#include "../header/Holidays.h"  // Include Holiday class header

using namespace std;

void displayMenu() {
    Date currentDate = Date::getCurrentDate();
    cout << "\nToday is: " << setw(2) << setfill('0') << currentDate.getDay() << "."
         << setw(2) << setfill('0') << currentDate.getMonth() << "."
         << currentDate.getYear() << endl;
    cout << "Enter a number between 1 and 7 to choose what you want to do:" << endl;
    cout << "1. Display calendar" << endl;
    cout << "2. Add event" << endl;
    cout << "3. Remove event" << endl;
    cout << "4. Show events" << endl;
    cout << "5. Show holidays" << endl;
    cout << "6. Display specific month" << endl;  // New option
    cout << "7. Exit" << endl; // Display menu options
}

void showAllEvents(Calendar& calendar, int year) {
    for (int month = 1; month <= 12; ++month) {
        for (int day = 1; day <= 31; ++day) {
            calendar.printEvents(day, month, year); // Show all events for a specific year
        }
    }
}

int main() {
    std::string eventsFile = "../EventLog.csv";
    std::string holidaysFile = "../Holidays.csv";

    FileHandler eventHandler(eventsFile);
    std::vector<Event> events = eventHandler.readEvents();

    FileHandler holidayHandler(holidaysFile);
    std::vector<Holiday> holidays = holidayHandler.readHolidays();

    Calendar calendar;

    for (const Event& event : events) {
        calendar.addEvent(event); // Read events and holidays from files
    }

    for (const Holiday& holiday : holidays) {
        calendar.addHoliday(holiday);
    }

    bool exit = false;
    while (!exit) {
        displayMenu();
        int choice;
        while (!(std::cin >> choice) || choice < 1 || choice > 7) {
            std::cout << "Invalid input. Please enter a number between 1 and 7: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Validate menu input
        }

        switch (choice) {
            case 1:
                calendar.printCurrentMonth();
                break;
            case 2:
                std::cout << "\nAdd event:\n";
                calendar.addEventFromUser(eventsFile);
                break;
            case 3:
                std::cout << "\nRemove event:\n";
                calendar.removeEventFromUser(eventsFile);
                events = eventHandler.readEvents();
                calendar = Calendar();
                for (const Event& event : events) {
                    calendar.addEvent(event);
                }
                break;
            case 4:
                std::cout << "\nShow events:\n";
                events = eventHandler.readEvents();
                calendar = Calendar();
                for (const Event& event : events) {
                    calendar.addEvent(event);
                }
                calendar.showAllEvents(Date::getCurrentDate().getYear());
                break;
            case 5:
                std::cout << "\nShow holidays:\n";
                holidays = holidayHandler.readHolidays();
                calendar = Calendar();
                for (const Holiday& holiday : holidays) {
                    calendar.addHoliday(holiday);
                }
                calendar.showHolidays();
                break;
            case 6: {
                std::cout << "\nEnter month name (e.g., January): ";
                std::string monthName;
                std::cin >> monthName;
                calendar.printMonthByName(Date::getCurrentDate().getYear(), monthName);
                break;
            }
            case 7:
                std::cout << "Exit" << std::endl;
                exit = true;
                break;
            default:
                std::cout << "Number out of range" << std::endl;
                break; // Execute menu options based on user choice
        }
    }

    return 0;
}
