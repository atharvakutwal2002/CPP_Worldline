#include <iostream>
#include <memory>
using namespace std;

class Car
{
private:
    string model;
    int year;

public:
    Car(string model, int year)
    {
        this->model = model;
        this->year = year;
    }

    void Drive() const
    {
        cout << "Driving " << model <<" "<< year  << endl;
    }

    void Stop()
    {
        cout << model << " stopped." << endl;
    }
};

void ProcessCar(const Car &car)
{
    cout << "Processing car: ";
    car.Drive();
    cout << endl;
}

void SmartPointerDemo()
{

    unique_ptr<Car> pCar(new Car("Maruti", 2022));
 
    
    pCar->Drive();
 
    
    ProcessCar(*pCar);

    
    pCar.reset(new Car("Honda", 2023));
    pCar->Drive();
}

int main()
{
    SmartPointerDemo();
    return 0;
}
