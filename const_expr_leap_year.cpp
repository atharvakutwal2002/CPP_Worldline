#include <iostream>
using namespace std;

constexpr bool isLeapYear(int year)
{
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
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

    return 0;
}
