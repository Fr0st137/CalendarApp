// source/main.cpp
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "../header/DateFile.h"
#include "../header/Event.h"
#include "../header/Holidays.h"
#include "../header/FileHandler.h"
#include "../header/Calendar.h"

using namespace std;

void displayMenu() {
    Date currentDate = Date::getCurrentDate();
    cout << "Today is: " << currentDate.getDay() << "." << currentDate.getMonth() << "." << currentDate.getYear() << endl;
    cout << "Enter a number between 1 and 8 to choose what you want to do:" << endl;
    cout << "1. Display calendar" << endl;
    cout << "2. Add event" << endl;
    cout << "3. Remove event" << endl;
    cout << "4. Add holiday" << endl;
    cout << "5. Show events" << endl;
    cout << "6. Show holidays" << endl;
    cout << "7. Show info" << endl;
    cout << "8. Exit" << endl;
}

int main() {
    FileHandler handler("../EventLog.csv");
    vector<Event> events = handler.readEvents();
    Calendar calendar;

    for (const Event& event : events) {
        calendar.addEvent(event);
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
                calendar.addEventFromUser("../EventLog.csv");
                break;
            case 3:
                cout << "Remove event" << endl;
                calendar.removeEventFromUser("../EventLog.csv");
                break;
            case 4:
                cout << "Add holiday" << endl;
                // Add logic to add holiday
                break;
            case 5:
                cout << "Show events" << endl;
                // Add logic to show events
                break;
            case 6:
                cout << "Show holidays" << endl;
                // Add logic to show holidays
                break;
            case 7:
                cout << "Show info" << endl;
                // Add logic to show info
                break;
            case 8:
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
