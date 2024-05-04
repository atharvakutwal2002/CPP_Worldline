#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{3, -4, 2, -8, 15, 267};
    auto print = [](const int &n)
    { cout << n << ' '; }; // lambda function
    cout << "before:\t";
    for_each(v.cbegin(), v.cend(), print);
    cout << '\n';
    // increment elements in-place
    for_each(v.begin(), v.end(), [](int &n)
             { n++; });
    cout << "after:\t";
    for_each(v.cbegin(), v.cend(), print);
    cout << '\n';
    struct Sum
    {
        void operator()(int n) { sum += n; } // lambda function
        int sum{0};
    };
    // invoke Sum::operator() for each element
    Sum s = for_each(v.cbegin(), v.cend(), Sum());
    cout << "sum:\t" << s.sum << '\n';
}