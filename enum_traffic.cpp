#include <iostream>

using namespace std;

enum class TrafficSignal
{

    SignalRed,

    SignalYellow,

    SignalGreen

};

int main()
{

    TrafficSignal signal = TrafficSignal::SignalYellow;

    switch (signal)
    {

    case TrafficSignal::SignalRed:

        cout << "Stop\n";
        break;

    case TrafficSignal::SignalYellow:

        cout << "Ready\n";
        break;

    case TrafficSignal::SignalGreen:

        cout << "Go\n";
        break;
    }

    return 0;
}
