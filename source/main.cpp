// File: source/main.cpp

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <limits>
#include "../header/Calendar.h"
#include "../header/DateFile.h"
#include "../header/Event.h"
#include "../header/FileHandler.h"
#include "../header/Holidays.h"

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
    cout << "7. Exit" << endl;
}

void showAllEvents(Calendar& calendar, int year) {
    for (int month = 1; month <= 12; ++month) {
        for (int day = 1; day <= 31; ++day) {
            calendar.printEvents(day, month, year);
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
        calendar.addEvent(event);
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                break;
        }
    }

    return 0;
}
