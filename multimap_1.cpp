#include <iostream>
#include <map>

using namespace std;

void displayMap(const multimap<int, int> &myMap)
{
    cout << "Multimap elements: " << endl;
    for (const auto &pair : myMap)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
}

int main()
{
    multimap<int, int> myMap;

    
    for (int i = 1; i <= 10; ++i)
    {
        myMap.insert(pair<int, int>(i, i * i));
    }
    cout << "Number of elements in multimap 1 : " << myMap.size() << endl;
    displayMap(myMap);

    
    multimap<int, int> copiedMap(myMap);
    cout << "Number of elements in multimap 2 : " << copiedMap.size() << endl;
    displayMap(copiedMap);

    
    auto it = copiedMap.begin();
    while (it != copiedMap.end())
    {
        if (it->first < 5)
        {
            it = copiedMap.erase(it);
        }
        else
        {
            ++it;
        }
    }

    cout << "Number of elements in multimap 2 : " << copiedMap.size() << endl;
    cout<<"After deleting elements "<<endl;
    displayMap(copiedMap);


    return 0;
}
