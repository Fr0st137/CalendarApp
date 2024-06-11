// File: source/main.cpp

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <limits> // For input validation
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
    cout << "6. Exit" << endl;
}

void showAllEvents(Calendar& calendar, int year) {
    for (int month = 1; month <= 12; ++month) {
        for (int day = 1; day <= 31; ++day) {
            calendar.printEvents(day, month, year); // Switched year and month for consistency
        }
    }
}

int main() {
    FileHandler eventHandler("../EventLog.csv");
    vector<Event> events = eventHandler.readEvents();

    FileHandler holidayHandler("../Holidays.csv");
    vector<Holiday> holidays = holidayHandler.readHolidays();

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
        // Input validation loop
        while (!(cin >> choice) || choice < 1 || choice > 6) {
            cout << "Invalid input. Please enter a number between 1 and 6: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } 

        switch (choice) { 
            case 1:
                calendar.printCurrentMonth();
                break;
            case 2:
                cout << "\nAdd event:\n";
                calendar.addEventFromUser("EventLog.csv");
                break;
            case 3:
                cout << "\nRemove event:\n";
                calendar.removeEventFromUser("EventLog.csv"); 
                // Refresh events after removing
                events = eventHandler.readEvents();
                calendar = Calendar(); // Reset calendar
                for (const Event& event : events) {
                    calendar.addEvent(event);
                }               
                break;
            case 4:
                cout << "\nShow events:\n";
                events = eventHandler.readEvents();
                calendar = Calendar();  // Reset calendar
                for (const Event& event : events) {
                    calendar.addEvent(event);
                }
                showAllEvents(calendar, Date::getCurrentDate().getYear());
                break;
            case 5:
                cout << "\nShow holidays:\n";
                calendar.showHolidays();
                break;
            case 6:
                cout << "Exit" << endl;
                exit = true;
                break;
            default:
                cout << "Number out of range" << endl;
                break;
        }
    }

    return 0;
}