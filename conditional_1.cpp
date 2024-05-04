#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Enter age " << endl;
    cin >> age;
    if (age < 18)
    {
        cout << "Not eligible to vote " << endl;
    }
    else
    {
        cout << "Eligible to vote " << endl;
    }
}