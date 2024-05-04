#include <iostream>
using namespace std;

constexpr int dayOfWeek(int year, int month, int day)
{
    return (day += month < 3 ? year-- : year - 2, 23 * month / 9 + day + 4 + year / 4 - year / 100 + year / 400) % 7;
}

int main()
{
    constexpr int year = 2024;
    constexpr int month = 3;
    constexpr int day = 3;
    constexpr int dayInd = dayOfWeek(year, month, day);

    switch (dayInd)
    {
    case 0:
        cout << "Sunday" << endl;
        break;
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    default:
        break;
    }
}