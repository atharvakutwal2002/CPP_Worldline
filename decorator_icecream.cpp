#include <iostream>
#include <string>

using namespace std;

class IceCream
{
public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
};

class VanillaIceCream : public IceCream
{
public:
    string getDescription() const override
    {
        return "Vanilla Ice Cream";
    }

    double cost() const override { return 160.0; }
};

class IceCreamDecorator : public IceCream
{
protected:
    IceCream *iceCream;

public:
    IceCreamDecorator(IceCream *ic)
        : iceCream(ic)
    {
    }

    string getDescription() const override
    {
        return iceCream->getDescription();
    }

    double cost() const override
    {
        return iceCream->cost();
    }
};

class ChocolateDecorator : public IceCreamDecorator
{
public:
    ChocolateDecorator(IceCream *ic)
        : IceCreamDecorator(ic)
    {
    }

    string getDescription() const override
    {
        return iceCream->getDescription() + " with Chocolate";
    }

    double cost() const override
    {
        return iceCream->cost() + 100.0;
    }
};

class CaramelDecorator : public IceCreamDecorator
{
public:
    CaramelDecorator(IceCream *ic)
        : IceCreamDecorator(ic)
    {
    }

    string getDescription() const override
    {
        return iceCream->getDescription() + " with Caramel";
    }

    double cost() const override
    {
        return iceCream->cost() + 150.0;
    }
};

int main()
{

    IceCream *vanillaIceCream = new VanillaIceCream();
    cout << "Order: " << vanillaIceCream->getDescription()
         << ", Cost: Rs." << vanillaIceCream->cost()
         << endl;

    IceCream *chocolateIceCream = new ChocolateDecorator(vanillaIceCream);
    cout << "Order: " << chocolateIceCream->getDescription()
         << ", Cost: Rs." << chocolateIceCream->cost()
         << endl;

    IceCream *caramelIceCream = new CaramelDecorator(chocolateIceCream);
    cout << "Order: " << caramelIceCream->getDescription()
         << ", Cost: Rs." << caramelIceCream->cost()
         << endl;

    delete vanillaIceCream;
    delete chocolateIceCream;
    delete caramelIceCream;

    return 0;
}
