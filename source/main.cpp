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

int menu(int choice = 0) {
    // Get current time
    system("CLS");
            cout << "Calendar" << endl;
            cout <<"Today is: "<< currDay << "." << currMonth << "." << currYear << endl;
            cout << "Enter a number between 1 and 6 to choose what do u want to do" << endl;
            cin >> choice;

    return choice;
}



int main(){


    FileHandler handler("../EventLog.csv"); 
    std::vector<Event> events = handler.readEvents();

    if (events.empty()) {
        std::cerr << "No events found in the file." << std::endl;
        return 1; // Indicate an error
    }

    std::cout << std::setw(12) << "Start Date" << std::setw(12) << "End Date" 
              << std::setw(12) << "Start Time" << std::setw(12) << "End Time"
              << std::setw(20) << "Subject" << std::endl;

    for (const Event& event : events) {
        std::cout << std::setw(12) << event.toString()       // Assuming you have a toString method in Date
                  << std::setw(12) << event.getEndTime()   
                  << std::setw(12) << event.getStartTime() 
                  << std::setw(12) << event.getEndTime()
                  << std::setw(20) << event.getSubject() << std::endl;
    }



    // while(true)
    // {
    //     switch (menu())
    //     {
    //     case 1:
    //         cout << "display calendar" << endl;
    //         break;
        
    //     case 2:
    //         cout << "add event" << endl;
    //         break;
        
    //     case 3:
    //         cout << "add event" << endl;
    //         break;

    //     case 4:
    //         cout << "show events" << endl;
    //         break;

    //     case 5:
    //         cout << "show holidays" << endl;
    //         break;

    //     case 6:
    //         cout << "show info" << endl;
    //         break;

    //     case 7:
    //         cout << "Exit" << endl;
    //         return 0;
    //         break;
        
    //     default:
    //         cout << "number out of range" << endl;
    //         break;
    //     }
    // }
}