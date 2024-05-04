#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int target)
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
    vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    int result = binarySearch(sortedArray, target);

    if (result != -1)
    {
        cout << " found  " << endl;
    }
    else
    {
        cout << " not found " << endl;
    }

    return 0;
}
