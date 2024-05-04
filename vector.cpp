#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec(100);

    int i;
    cout << "vector size = " << vec.size() << endl;

    for (i = 0; i < 5; i++)
    {
        vec.push_back(i);
    }

    cout << "extended vector size = " << vec.size() << endl;

    for (i = 0; i < 5; i++)
    {
        cout << "value of vec [" << i << "] = " << vec[i] << endl;
    }
    return 0;
}