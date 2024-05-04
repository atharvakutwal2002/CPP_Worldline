#include<iostream>
using namespace std;

class Engine{
    public:
    void start(){
        cout<<"Engine started "<<endl;
    }
    void stop(){
        cout<<"Engine stopped "<<endl;
    }
};

class Lights{
    public:
    void TurnOn(){
        cout<<"Lights On"<<endl;
    }
    void turnOff(){
        cout<<"Lights off"<<endl;
    }
};

class Car{
    private:
    Engine engine ;
    Lights lights;
    public:
    void startCar(){
        engine.start();
        lights.TurnOn();
        cout<<"Car is ready to drive "<<endl;
        cout<<"-------------------------------------"<<endl;
    }
    void stopCar(){
        lights.turnOff();
        engine.stop();
        cout<<"Car has stopped "<<endl;
        cout<<"-------------------------------------"<<endl;
    }
    void redSignal(){
        lights.turnOff();
        engine.stop();
        cout<<"Car has stopped . Waiting for signal to be green  "<<endl;
        cout<<"-------------------------------------"<<endl;
    }
    void greenSignal(){
        engine.start();
        lights.TurnOn();
        cout<<"Green signal appeared and car is ready to drive "<<endl;
        cout<<"-------------------------------------"<<endl;
    }

};

int main(){
    Car car;
    car.startCar();
    car.redSignal();
    car.greenSignal();
    car.stopCar();
    return 0;
}