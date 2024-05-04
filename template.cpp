#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
int binarySearch(vector<T> arr, T target)
{

    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{

    vector<int> intArray = {23, 11, 44, 35, 66, 55, 88, 91};
    sort(intArray.begin(), intArray.end());
    cout << "Array elements : " << endl;
    for (int i = 0; i < intArray.size(); i++)
    {
        cout << intArray[i] << " ";
    }
    cout << endl;

    int intTarget = 11;

    int intResult = binarySearch(intArray, intTarget);

    if (intResult != -1)
    {
        cout << "Integer target found at index " << intResult << endl;
    }
    else
    {
        cout << "Integer target not found." << endl;
    }
    int intTarget2 = 91;

    int intResult2 = binarySearch(intArray, intTarget2);

    if (intResult2 != -1)
    {
        cout << "Integer target found at index " << intResult2 << endl;
    }
    else
    {
        cout << "Integer target not found." << endl;
    }

    int intTarget3 = 99;

    int intResult3 = binarySearch(intArray, intTarget3);

    if (intResult3 != -1)
    {
        cout << "Integer target found at index " << intResult3 << endl;
    }
    else
    {
        cout << "Integer target not found." << endl;
    }

    return 0;
}
