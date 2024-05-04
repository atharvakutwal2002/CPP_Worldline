#include <iostream>

using namespace std;

int main()
{
    int marks[5];
    int total = 0;
    float average;

    cout << "Enter the marks of 5 subjects:\n";

    for (int i = 0; i < 5; ++i)
    {
        cout << "Subject " << i + 1 << ": ";
        cin >> marks[i];
        total += marks[i];
    }

    
    average = (total) / 5;

    
    cout << "Total marks: " << total << endl;
    cout << "Average marks: " << average << endl;

    char grade;
    if (average >= 90)
        grade = 'S';
    else if (average >= 80 && average < 90)
        grade = 'A';
    else if (average >= 70 && average < 80)
        grade = 'B';
    else if (average >= 60 && average < 70)
        grade = 'C';
    else if (average >= 50 && average < 60)
        grade = 'D';
    else
        grade = 'F';

    cout << "Grade: " << grade << endl;

    return 0;
}
