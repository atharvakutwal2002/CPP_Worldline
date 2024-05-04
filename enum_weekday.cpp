#include <iostream>
using namespace std;

enum class Weekday
{
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat,
    Sun
};

int main()
{
    Weekday today = Weekday::Mon;

    switch (today)
    {
    case Weekday::Mon:
        cout << "Today is Monday" << endl;
        break;
    case Weekday::Tue:
        cout << "Today is Tuesday" << endl;
        break;
    case Weekday::Wed:
        cout << "Today is Wednesday" << endl;
        break;
    case Weekday::Thu:
        cout << "Today is Thursday" << endl;
        break;
    case Weekday::Fri:
        cout << "Today is Friday" << endl;
        break;
    case Weekday::Sat:
        cout << "Today is Saturday" << endl;
        break;
    case Weekday::Sun:
        cout << "Today is Sunday" << endl;
        break;
    default:
        cout << "Invalid day!" << endl;
    }

    return 0;
}
