#include <iostream>
using namespace std;

class Singleton
{
public:
    // Clients can access the single instance
    static Singleton *getInstance();
    void setValue(int val) { value_ = val; }
    int getValue() { return (value_); }

protected: //? private or public
    int value_;

private:
    static Singleton *inst_; // single instance
    // private constructor - no use, even remove or comment/hide
    Singleton() : value_(0) {}
    Singleton(const Singleton &);
};

// Define the static Singleton pointer
Singleton *Singleton::inst_ = NULL;

Singleton *Singleton::getInstance()
{
    if (inst_ == NULL)
    {
        inst_ = new Singleton();
    }
    return (inst_);
}

int main()
{
    Singleton *p1 = Singleton::getInstance();
    cout << "Value = " << p1->getValue() << '\n'; // 0
    p1->setValue(10);
    cout << "Value = " << p1->getValue() << '\n'; // 10
    Singleton *p2 = Singleton::getInstance();
    cout << "Value = " << p2->getValue() << '\n'; // 10
    p1->setValue(20);
    cout << "Value = " << p1->getValue() << '\n'; // 20
    cout << "Value = " << p2->getValue() << '\n'; // 20
    p2->setValue(30);
    cout << "Value = " << p1->getValue() << '\n'; // 30
    cout << "Value = " << p2->getValue() << '\n'; // 30

    // create a function to assign new value / value - 5
}