#include <iostream>
#include <memory>
using namespace std;

class ticketMachine
{
private:
    ticketMachine()
    {
        total_tickets = 100;
    }

protected:
    int total_tickets;

public:
    static shared_ptr<ticketMachine> createInstance()
    {
        return shared_ptr<ticketMachine>(new ticketMachine());
    }

    void bookTickets(int x)
    {
        total_tickets -= x;
    }

    int tickets_remaining()
    {
        return total_tickets;
    }
};

int main()
{

    shared_ptr<ticketMachine> t1 = ticketMachine::createInstance();
    t1->bookTickets(3);
    cout << "Tickets remaining after booking using t1: " << t1->tickets_remaining() << endl;

    shared_ptr<ticketMachine> t2 = t1;

    t2->bookTickets(3);

    cout << "Tickets remaining after booking using t2: " << t1->tickets_remaining() << endl;

    return 0;
}
