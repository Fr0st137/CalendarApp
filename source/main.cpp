#include <iostream>
#include <chrono>
#include <ctime>

#include "DateFile.cpp"
#include "FileHandler.cpp"

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
    
    while(true)
    {
        switch (menu())
        {
        case 1:
            cout << "display calendar" << endl;
            break;
        
        case 2:
            cout << "add event" << endl;
            break;
        
        case 3:
            cout << "add event" << endl;
            break;

        case 4:
            cout << "show events" << endl;
            break;

        case 5:
            cout << "show holidays" << endl;
            break;

        case 6:
            cout << "show info" << endl;
            break;

        case 7:
            cout << "Exit" << endl;
            return 0;
            break;
        
        default:
            cout << "number out of range" << endl;
            break;
        }
    }
}