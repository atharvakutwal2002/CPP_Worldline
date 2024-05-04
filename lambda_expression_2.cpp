
#include <bits/stdc++.h>

using namespace std;

int main()

{

    vector<int> v{4, 1, 3, 5, 2, 3, 1, 7};

    for_each(v.begin(), v.end(), [](int i)
             { cout << i << " "; });

    cout << endl;

    // below snippet find first number greater than 4

    // find_if searches for an element for which

    vector<int>::iterator p = find_if(v.begin(), v.end(), [](int i)
                                      { return i > 4; });

    cout << "First number greater than 4 is : " << *p << endl;

    // function to sort vector, lambda expression is for

    // non-increasing order Compiler can make out return type

    // bool, but shown here just for explanation

    sort(v.begin(), v.end(), [](const int &a, const int &b) -> bool
         { return a > b; });

    for_each(v.begin(), v.end(), [](int i)
             { cout << i << " "; });

    cout << endl;

    // function to count numbers greater than or equal to 5

    int count_5 = count_if(v.begin(), v.end(), [](int a)

                           { return (a >= 5); });

    cout << "The number of elements greater than or equal to 5 is : " << count_5 << endl;

    // function for removing duplicate element (after sorting

    // duplicate comes together)

    p = unique(v.begin(), v.end(), [](int a, int b)

               { return a == b; });

    // resizing vector to make size equal to total different number

    v.resize(distance(v.begin(), p));

    for_each(v.begin(), v.end(), [](int i)
             { cout << i << " "; });

    cout << endl;

    auto square = [](int i)
    { return i * i; };

    cout << "Square of 5 is : " << square(5) << endl;
}