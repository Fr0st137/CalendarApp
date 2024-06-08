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
    cout << "Calendar" << endl;
    Date currentDate = Date::getCurrentDate();
    cout << "Today is: " << currentDate.getDay() << "." << currentDate.getMonth() << "." << currentDate.getYear() << endl;
    cout << "Enter a number between 1 and 7 to choose what you want to do:" << endl;
    cout << "1. Display calendar" << endl;
    cout << "2. Add event" << endl;
    cout << "3. Add holiday" << endl;
    cout << "4. Show events" << endl;
    cout << "5. Show holidays" << endl;
    cout << "6. Show info" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    FileHandler handler("../EventLog.csv"); // locatino of file with events 
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
                cout << "add event" << endl;
                // Add logic to add event
                break;
            case 3:
                cout << "add holiday" << endl;
                // Add logic to add holiday
                break;
            case 4:
                cout << "show events" << endl;
                // Add logic to show events
                break;
            case 5:
                cout << "show holidays" << endl;
                // Add logic to show holidays
                break;
            case 6:
                cout << "show info" << endl;
                // Add logic to show info
                break;
            case 7:
                cout << "Exit" << endl;
                exit = true;
                break;
            default:
                cout << "number out of range" << endl;
                break;
        }
    }

    return 0;
}