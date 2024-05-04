#include <iostream>
using namespace std;

float average(int s1, int s2, int s3, int s4, int s5)
{
    return (s1 + s2 + s3 + s4 + s5) / 5;
}

string display_result(float average)
{
    if (average > 90)
    {
        return "A*";
    }
    else if (average >= 81 && average <= 90)
    {
        return "A";
    }
    else if (average >= 71 && average <= 80)
    {
        return "B";
    }
    else if (average >= 61 && average <= 70)
    {
        return "C";
    }
    else if (average >= 51 && average <= 60)
    {
        return "D";
    }
    else
    {
        return "Fail";
    }
}

int main()
{
    while (true)
    {
        int command;
        cout << "Enter 1 to compute result and 0 to stop " << endl;
        cin >> command;
        if (command)
        {
            cout << "Enter the marks of 5 subjects " << endl;
            int s1, s2, s3, s4, s5;
            cin >> s1 >> s2 >> s3 >> s4 >> s5;
            float avg = average(s1, s2, s3, s4, s5);
            string res = display_result(avg);
            cout <<"The result is "<< res<<endl;
            cout<<"===================================================================="<<endl;
        }
        else
        {
            break;
        }
    }

    return 0;
}