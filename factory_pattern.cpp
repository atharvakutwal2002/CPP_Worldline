#include <iostream>
#include <string>

using namespace std;


class Animal {
public:
    virtual void emitSound() = 0;
    virtual ~Animal() {} 
};


class Dog : public Animal {
public:
    void emitSound() override {
        cout << "Dog barks" << endl;
    }
};


class Cat : public Animal {
public:
    void emitSound() override {
        cout << "Cat meows" << endl;
    }
};


class Bird : public Animal {
public:
    void emitSound() override {
        cout << "Bird sings" << endl;
    }
};

int main() {
    cout << "Enter animal type (dog, cat, or bird): ";
    string animalType;
    cin >> animalType;

    Animal* animal = nullptr;
    if (animalType == "dog") {
        animal = new Dog();
    } else if (animalType == "cat") {
        animal = new Cat();
    } else if (animalType == "bird") {
        animal = new Bird();
    } else {
        cout << "Invalid animal type entered." << endl;
        return 1;
    }

    animal->emitSound();

    
    delete animal;

    return 0;
}
