#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
int linearSearch(const vector<T> &arr, const T &key)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

template <typename T>
int binarySearch(const vector<T> &arr, const T &key)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{

    vector<int> intArray = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int intKey;
    cout << "Enter the int to search " << endl;
    cin >> intKey;

    int intLinearResult = linearSearch(intArray, intKey);
    if (intLinearResult != -1)
        cout << "Integer found at index: " << intLinearResult << endl;
    else
        cout << "Integer not found!" << endl;

    sort(intArray.begin(), intArray.end());

    int intBinaryResult = binarySearch(intArray, intKey);
    if (intBinaryResult != -1)
        cout << "Integer found at index: " << intBinaryResult << endl;
    else
        cout << "Integer not found!" << endl;

    vector<float> floatArray = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f};
    float floatKey = 5.5f;
    cout << "Enter float to search " << endl;
    cin >> floatKey;

    int floatLinearResult = linearSearch(floatArray, floatKey);
    if (floatLinearResult != -1)
        cout << "Float found at index: " << floatLinearResult << endl;
    else
        cout << "Float not found!" << endl;

    sort(floatArray.begin(), floatArray.end());

    int floatBinaryResult = binarySearch(floatArray, floatKey);
    if (floatBinaryResult != -1)
        cout << "Float found at index: " << floatBinaryResult << endl;
    else
        cout << "Float not found!" << endl;

    vector<char> charArray = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char charKey = 'f';

    cout << "Enter char to search " << endl;
    cin >> charKey;
    int charLinearResult = linearSearch(charArray, charKey);
    if (charLinearResult != -1)
        cout << "Char found at index: " << charLinearResult << endl;
    else
        cout << "Char not found!" << endl;

    sort(charArray.begin(), charArray.end());

    int charBinaryResult = binarySearch(charArray, charKey);
    if (charBinaryResult != -1)
        cout << "Char found at index: " << charBinaryResult << endl;
    else
        cout << "Char not found!" << endl;

    return 0;
}
