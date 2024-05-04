#include <iostream>
#include <string>

using namespace std;

// Component interface
class Pizza
{
public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Pizza() {}
};

// Concrete Component
class BasicPizza : public Pizza
{
public:
    string getDescription() const override
    {
        return "Basic Pizza";
    }

    double cost() const override
    {
        return 100.0;
    }
};

// Decorator abstract class
class PizzaDecorator : public Pizza
{
protected:
    Pizza *pizza;

public:
    PizzaDecorator(Pizza *p) : pizza(p) {}

    string getDescription() const override
    {
        return pizza->getDescription();
    }

    double cost() const override
    {
        return pizza->cost();
    }

    virtual ~PizzaDecorator()
    {
        delete pizza;
    }
};

// Concrete Decorators
class CheeseDecorator : public PizzaDecorator
{
public:
    CheeseDecorator(Pizza *p) : PizzaDecorator(p) {}

    string getDescription() const override
    {
        return pizza->getDescription() + ", Cheese";
    }

    double cost() const override
    {
        return pizza->cost() + 20.0;
    }
};

class PepperoniDecorator : public PizzaDecorator
{
public:
    PepperoniDecorator(Pizza *p) : PizzaDecorator(p) {}

    string getDescription() const override
    {
        return pizza->getDescription() + ", Pepperoni";
    }

    double cost() const override
    {
        return pizza->cost() + 30.0;
    }
};

int main()
{
    Pizza *basicPizza = new BasicPizza();
    cout << "Order: " << basicPizza->getDescription() << ", Cost: " << basicPizza->cost() << endl;

    Pizza *cheesePizza = new CheeseDecorator(basicPizza);
    cout << "Order: " << cheesePizza->getDescription() << ", Cost: " << cheesePizza->cost() << endl;

    Pizza *pepperoniPizza = new PepperoniDecorator(basicPizza);
    cout << "Order: " << pepperoniPizza->getDescription() << ", Cost: " << pepperoniPizza->cost() << endl;

    Pizza *comboPizza = new PepperoniDecorator(new CheeseDecorator(basicPizza));
    cout << "Order: " << comboPizza->getDescription() << ", Cost: " << comboPizza->cost() << endl;

    delete basicPizza;
    delete cheesePizza;
    delete pepperoniPizza;
    delete comboPizza;

    return 0;
}
