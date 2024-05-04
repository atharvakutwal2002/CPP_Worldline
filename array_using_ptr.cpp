#include <iostream>

using namespace std;

int main()
{

    const int arraySize = 5;

    int *dynamicArray = new int[arraySize];

    for (int i = 0; i < arraySize; ++i)
    {
        dynamicArray[i] = i * 2;
    }

    for (int i = 0; i < arraySize; ++i)
    {
        cout << dynamicArray[i] << " ";
    }

    delete[] dynamicArray;

    return 0;
}
