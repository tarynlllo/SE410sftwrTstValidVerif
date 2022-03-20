#include <iostream>
#include <ctime>

using namespace std;

class Date
{
    bool isLeapYear(int);
    void CalcNextDay(int);
};

bool Date::isLeapYear(int year)
{
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return true;
    else
        return false;
}

void Date::CalcNextDay(int date)
{
    int yyyy, month, days, totalDays;

    // Total days for Feb in leapyear
    if(isLeapYear(yyyy))
    {
        if (month == 2)
            totalDays = 29;
    }
    // Total days for Feb in non-leapyear
    else
    {
        if (month == 2) 
            totalDays = 28;
    }
    // Total days for all other months
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        totalDays = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        totalDays = 30;
    
    // Test input for out of range
    if ((0 > month > 12) || (0 > days > totalDays) || (1812 > yyyy > 2012))
    {
        cout << "Invalid Input Date";
    }
    else
    {
        days++;
        if (days > totalDays)
        {
            month++;
            days = 1;
            if(month > 12)
                yyyy++;
        }
    }
}