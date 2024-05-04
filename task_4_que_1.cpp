#include <iostream>
using namespace std;

class ticketMachine
{
private:
    ticketMachine()
    {
        total_tickets = 100;
    }

    static ticketMachine *t_machine;

protected:
    int total_tickets;

public:
    static ticketMachine *getInstance()
    {
        if (t_machine == NULL)
        {
            t_machine = new ticketMachine();
        }

        return t_machine;
    }

    void bookTickets(int x)
    {
        total_tickets -= x;
    }

    int tickets_remaining()
    {
        return total_tickets;
    }

    ticketMachine(const ticketMachine &) = delete;
    ticketMachine &operator=(const ticketMachine &) = delete;

    ~ticketMachine()
    {
        delete t_machine;
    }
};

ticketMachine *ticketMachine::t_machine = nullptr;

int main()
{
    ticketMachine *t1 = ticketMachine::getInstance();

    cout << "Instance t1 ...." << endl;

    cout << "Tickets remaining: " << t1->tickets_remaining() << endl;

    t1->bookTickets(3);

    cout << "Tickets remaining after booking: " << t1->tickets_remaining() << endl;

    ticketMachine *t2 = ticketMachine::getInstance();

    cout << "Instance t2 ...." << endl;

    cout << "Tickets remaining: " << t2->tickets_remaining() << endl;

    t2->bookTickets(3);

    cout << "Tickets remaining after booking: " << t2->tickets_remaining() << endl;

    return 0;
}
