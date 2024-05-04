#include <bits/stdc++.h>
using namespace std;
int main()
{
    // declare integer value_type for priority queue
    priority_queue<int>::value_type AnInt;
    // declare string value_type for priority queue
    priority_queue<string>::value_type AString;
    // Declares priority_queues
    priority_queue<int> q1;
    priority_queue<string> q2;

    // Here AnInt acts as a variable of int data type
    AnInt = 20;
    cout << "The value_type is AnInt = " << AnInt << endl;
    q1.push(AnInt);
    AnInt = 30;
    cout << "The value_type is AnInt = " << AnInt << endl;
    q1.push(AnInt);
    AString = "Hello";
    q2.push(AString);
    AString = "Students";
    q2.push(AString);
    cout << "Top element of the integer priority_queue is: "
         << q1.top() << endl;
    cout << "Top element of the string priority_queue is: "
         << q2.top() << endl;
    return 0;
}