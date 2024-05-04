#include <iostream>
using namespace std;

int main() {
    int low = 1;
    int high = 100;
    int guess;
    string response;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Think of a number between 1 and 100.\n";
    cout << "You need to respond with 'lesser', 'greater', or 'yes'.\n\n";

    while (true) {
        guess = (low + high) / 2;
        cout << "Is number " << guess << "? (Type 'lesser', 'greater', or 'yes'): ";
        cin >> response;

        if (response == "lesser") {
            high = guess - 1;
        } else if (response == "greater") {
            low = guess + 1;
        } else if (response == "yes") {
            cout << " guessed your number.\n";
            break;
        } else {
            cout << " options are 'lesser', 'greater', or 'yes'.\n";
        }
    }

    return 0;
}
