// File: source/main.cpp

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "../header/Calendar.h"
#include "../header/DateFile.h"
#include "../header/Event.h"
#include "../header/FileHandler.h"
#include "../header/Holidays.h"

using namespace std;

void displayMenu() {
    Date currentDate = Date::getCurrentDate();
    cout << "Today is: " << setw(2) << setfill('0') << currentDate.getDay() << "."
         << setw(2) << setfill('0') << currentDate.getMonth() << "."
         << currentDate.getYear() << endl;
    cout << "Enter a number between 1 and 8 to choose what you want to do:" << endl;
    cout << "1. Display calendar" << endl;
    cout << "2. Add event" << endl;
    cout << "3. Remove event" << endl;
    cout << "4. Add holiday" << endl;
    cout << "5. Show events" << endl;
    cout << "6. Show holidays" << endl;
    cout << "7. Exit" << endl;
}

void showAllEvents(Calendar& calendar, int year) {
    for (int month = 1; month <= 12; ++month) {
        for (int day = 1; day <= 31; ++day) {
            calendar.printEvents(day, year, month);
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
        cin >> choice;

        switch (choice) {
            case 1:
                calendar.printCurrentMonth();
                break;
            case 2:
                cout << "Add event" << endl;
                calendar.addEventFromUser("EventLog.csv");
                break;
            case 3:
                cout << "Remove event" << endl;
                calendar.removeEventFromUser("EventLog.csv");
                events = eventHandler.readEvents();
                calendar = Calendar();
                for (const Event& event : events) {
                    calendar.addEvent(event);
                }
                break;
            case 4:
                cout << "Add holiday" << endl;
                // Add logic to add holiday
                break;
            case 5:
                cout << "Show events" << endl;
                events = eventHandler.readEvents();
                calendar = Calendar();
                for (const Event& event : events) {
                    calendar.addEvent(event);
                }
                showAllEvents(calendar, Date::getCurrentDate().getYear());
                break;
            case 6:
                cout << "Show holidays" << endl;
                calendar.showHolidays();
                break;
            case 7:
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
