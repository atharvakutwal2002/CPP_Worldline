#include <iostream>
using namespace std;

constexpr bool isLeapYear(int year)
{
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

constexpr int getDaysInMonth(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return -1;
    }
}

int main()
{
    constexpr int year = 2024;

    switch (isLeapYear(year))
    {
    case true:
        cout << year << " is a leap year." << endl;
        break;
    case false:
        cout << year << " is not a leap year." << endl;
        break;
    }

    cout << "Number of days in February in " << year << ": " << getDaysInMonth(2, year) << endl;

    return 0;
}
