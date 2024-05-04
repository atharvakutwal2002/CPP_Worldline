#include <bits/stdc++.h>

using namespace std;

class TicketCounter
{
private:
    int totalTickets;

public:
    TicketCounter(int initialTickets)
    {
        this->totalTickets = initialTickets;
    }

    void bookTickets(int numTickets)
    {
        totalTickets -= numTickets;
    }

    int getAvailableTickets() const
    {
        return totalTickets;
    }
};

class TicketBookingSystem
{
private:
    vector<shared_ptr<TicketCounter>> counters;

public:
    TicketBookingSystem(int numCounters, int ticketsPerCounter)
    {
        for (int i = 0; i < numCounters; ++i)
        {
            auto counter = make_shared<TicketCounter>(ticketsPerCounter);
            counters.push_back(counter);
        }
    }

    void bookTickets(const string &source, const string &destination, int numTickets)
    {
        for (auto &counter : counters)
        {
            counter->bookTickets(numTickets);
        }
        cout << "Tickets booked from " << source << " to " << destination << endl;
    }

    void displayAvailableTickets() const
    {
        int counterNum = 1;
        for (const auto &counter : counters)
        {
            cout << "Counter " << counterNum++ << ": " << counter->getAvailableTickets() << " tickets available" << endl;
        }
    }
};

int main()
{
    array<tuple<string, string, int>, 2> bookings = {
        make_tuple("Chennai", "Delhi", 5),
        make_tuple("Chennai", "Pune", 3)};

    TicketBookingSystem bookingSystem(2, 100);

    for (const auto &[source, destination, numTickets] : bookings)
    {
        bookingSystem.bookTickets(source, destination, numTickets);
    }

    bookingSystem.displayAvailableTickets();

    return 0;
}
