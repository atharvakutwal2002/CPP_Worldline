#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom comparison function using spaceship operator for integers
auto compare(int a, int b)
{
    return (a <=> b);
}

// Function to find common elements between two arrays
vector<int> findCommonElements(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<int> commonElements;
    // Sort both arrays
    vector<int> sortedArr1 = arr1;
    vector<int> sortedArr2 = arr2;
    sort(sortedArr1.begin(), sortedArr1.end());
    sort(sortedArr2.begin(), sortedArr2.end());

    // Iterate through both arrays
    auto it1 = sortedArr1.begin();
    auto it2 = sortedArr2.begin();
    while (it1 != sortedArr1.end() && it2 != sortedArr2.end())
    {
        auto cmp = compare(*it1, *it2);
        if (cmp == 0)
        {
            // Common element found
            commonElements.push_back(*it1);
            ++it1;
            ++it2;
        }
        else if (cmp < 0)
        {
            ++it1;
        }
        else
        {
            ++it2;
        }
    }
    return commonElements;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6, 7};

    vector<int> commonElements = findCommonElements(arr1, arr2);

    if (commonElements.empty())
    {
        cout << "No common elements found." << endl;
    }
    else
    {
        cout << "Common elements: ";
        for (const auto &elem : commonElements)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
