#include <iostream>
using namespace std;

enum class Month
{
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
};

int main()
{
    Month month = Month::Jan;

    switch (month)
    {
    case Month::Jan:
    case Month::Mar:
    case Month::May:
    case Month::Jul:
    case Month::Aug:
    case Month::Oct:
    case Month::Dec:
        cout << "The month has 31 days" << endl;
        break;
    case Month::Apr:
    case Month::Jun:
    case Month::Sep:
    case Month::Nov:
        cout << "The month has 30 days" << endl;
        break;
    case Month::Feb:
        cout << "The month has 28 or 29 days" << endl;
        break;
    default:
        cout << "Invalid month!" << endl;
    }

    return 0;
}
