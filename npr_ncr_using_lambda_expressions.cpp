#include <iostream>

using namespace std;

int calculateFactorial(int n)
{
    return (n == 1 || n == 0) ? 1 : calculateFactorial(n - 1) * n;
}

auto calculatePermutation = [](int n, int r)
{
    return calculateFactorial(n) / calculateFactorial(n - r);
};

auto calculateCombination = [](int n, int r)
{
    return calculateFactorial(n) / (calculateFactorial(r) * calculateFactorial(n - r));
};

int main()
{
    int totalElements = 3;
    int selectedElements = 2;

    cout << " (nPr) of " << totalElements << " and " << selectedElements << " is: " << calculatePermutation(totalElements, selectedElements) << endl;
    cout << " (nCr) of " << totalElements << " and " << selectedElements << " is: " << calculateCombination(totalElements, selectedElements) << endl;

    return 0;
}
