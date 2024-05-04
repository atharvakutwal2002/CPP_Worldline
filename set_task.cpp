#include <iostream>
#include <set>
using namespace std;

int main()
{

    set<int> set1 = {1, 2, 3, 4, 5};
    set<int> set2 = {3, 4, 5, 6, 7};

    set<int> intersection;
    for (auto it = set1.begin(); it != set1.end(); ++it)
    {
        if (set2.find(*it) != set2.end())
        {
            intersection.insert(*it);
        }
    }

    set<int> _union = set1;
    _union.insert(set2.begin(), set2.end());

    cout << "Set 1: ";
    for (auto const &elem : set1)
    {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Set 2: ";
    for (auto const &elem : set2)
    {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Intersection: ";
    for (auto const &elem : intersection)
    {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Union: ";
    for (auto const &elem : _union)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
