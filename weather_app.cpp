#include <iostream>
#include <vector>

using namespace std;

// Observer interface
class Observer {
public:
    virtual ~Observer() {}
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

// Subject interface
class Subject {
public:
    virtual ~Subject() {}
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

// Concrete Subject: Weather Station
class WeatherStation : public Subject {
private:
    vector<Observer*> observers;
    float temperature;
    float humidity;
    float pressure;

public:
    void registerObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        auto it = find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers() override {
        for (auto observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }

    void setMeasurements(float temp, float hum, float press) {
        temperature = temp;
        humidity = hum;
        pressure = press;
        measurementsChanged();
    }

private:
    void measurementsChanged() {
        notifyObservers();
    }
};

// Concrete Observer: Display
class Display : public Observer {
private:
    float temperature;
    float humidity;
    float pressure;

public:
    void update(float temp, float hum, float press) override {
        temperature = temp;
        humidity = hum;
        pressure = press;
        display();
    }

    void display() {
        cout << "Temperature: " << temperature << "F, Humidity: " << humidity << "%, Pressure: " << pressure << "hPa" << endl;
    }
};

int main() {
    // Create WeatherStation and Displays
    WeatherStation weatherStation;
    Display display1, display2;

    // Register Displays with WeatherStation
    weatherStation.registerObserver(&display1);
    weatherStation.registerObserver(&display2);

    // Simulate weather updates
    weatherStation.setMeasurements(75, 60, 30.4f);
    weatherStation.setMeasurements(80, 65, 30.2f);

    // Unregister one display
    weatherStation.removeObserver(&display2);

    // Simulate another weather update
    weatherStation.setMeasurements(85, 70, 30.1f);

    return 0;
}
