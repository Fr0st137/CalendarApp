#pragma once

#include <string>
#include <iostream>

using namespace std;

string getDay();
string monthName();
int monthDaysNum();



class Date {
    private:
        int day;
        int year = 2024;

        struct month{
            string name;
            int days;
        };

    public:
        month month;
};