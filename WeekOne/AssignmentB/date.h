#include <iostream>
#include <ctime>

using namespace std;

class Date
{
    //friend ostream& operator<<(ostream&, const Date &);
    friend istream& operator>>(istream&, Date &);
    public:
        Date();
        void setDate(int,int,int);
        void CalcNextDay();

    private:
        int mm,dd,yyyy;
        bool isLeapYear(int);
};

istream& operator>>(istream& is, Date& date)
{
    char ignore;
    int mm, dd, yyyy;

    is >> mm;
    is >> ignore;
    is >> dd;
    is >> ignore;
    is >> yyyy;

    date.setDate(mm, dd, yyyy);

    return is;
}

void Date::setDate(int month, int day, int year)
{
    mm = month;
    dd = day;
    yyyy = year;
}

bool Date::isLeapYear(int year)
{
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return true;
    else
        return false;
}

void Date::CalcNextDay()
{
    int totalDays;

    // Total days for Feb in leapyear
    if(isLeapYear(yyyy) == true)
    {
        if (mm == 2)
            totalDays = 29;
    }
    // Total days for Feb in non-leapyear
    else
    {
        if (mm == 2) 
            totalDays = 28;
    }
    // Total days for all other months
    if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        totalDays = 31;
    if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        totalDays = 30;
    
    // Test input for out of range
    if ((0 > mm > 12) || (0 > dd > totalDays) || (1812 > yyyy > 2012))
    {
        cout << "Invalid Input Date";
    }
    else
    {
        dd++;
        if (dd > totalDays)
        {
            mm++;
            dd = 1;
            if(mm > 12)
                yyyy++;
        }
    }
}


