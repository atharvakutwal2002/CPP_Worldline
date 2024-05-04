#include <iostream>
using namespace std;

template <int... Args>
constexpr int sum_of_natural_numbers_right_fold()
{
    return (0 + ... + Args);
}

template <int... Args>
constexpr int sum_of_natural_numbers_left_fold()
{
    return (Args + ... + 0);
}

int main()
{
    constexpr int N = 10;

    int sum_right = sum_of_natural_numbers_right_fold<1, 2, 3, 4, 5, 6, 7, 8, 9, 10>();
    cout << "Sum of the first " << N << " natural numbers using binary right fold expression: " << sum_right << endl;

    int sum_left = sum_of_natural_numbers_left_fold<1, 2, 3, 4, 5, 6, 7, 8, 9, 10>();
    cout << "Sum of the first " << N << " natural numbers using binary left fold expression: " << sum_left << endl;

    return 0;
}
