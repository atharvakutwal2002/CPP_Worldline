#include <iostream>
using namespace std;

template <int... Args>
constexpr int factorial_right_fold()
{
    return (1 * ... * Args);
}

template <int... Args>
constexpr int factorial_left_fold()
{
    return (... * Args);
}

int main()
{

    int factorial_right = factorial_right_fold<1, 2, 3, 4, 5>();
    cout << "Factorial using binary right fold expression: " << factorial_right << endl;

    int factorial_left = factorial_left_fold<5, 4, 3, 2, 1>();
    cout << "Factorial using binary left fold expression: " << factorial_left << endl;

    return 0;
}