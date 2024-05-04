#include <iostream>

using namespace std;

constexpr char calculateGrade(int marks)
{
    if (marks < 50)
    {
        return 'F';
    }
    else if (marks >= 50 && marks < 60)
    {
        return 'D';
    }
    else if (marks >= 60 && marks < 70)
    {
        return 'C';
    }
    else if (marks >= 70 && marks < 80)
    {
        return 'B';
    }
    else if (marks >= 80 && marks < 90)
    {
        return 'A';
    }

    return 'x';
}

char calculateGradeFromConstantMarks()
{
    constexpr int marks = 86;
    return calculateGrade(marks);
}

int main()
{
    char grade = calculateGradeFromConstantMarks();
    if (grade == 'x')
    {
        cout << "Grade: A+" << endl;
    }
    else
    {
        cout << "Grade: " << grade << endl;
    }

    return 0;
}
