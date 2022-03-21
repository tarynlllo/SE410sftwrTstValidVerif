#include <iostream>
#include <ctime>
#include "date.h"

using namespace std;

Date date;

int main()
{
    cout << " DateTester " << endl;
    cout << "* * * * * * *" << endl;
    cout << "Enter a date in range 1/1/1812 - 12/31/2012" << endl;
    cout << "User date: ";
    cin >> date;
    date.CalcNextDay();

    return 0;
}