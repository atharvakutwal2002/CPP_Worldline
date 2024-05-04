#include <iostream>
#include <vector>

using namespace std;

class Search
{

    vector<int> data;
    int vectorSize;

public:
    void inputData()
    {
        int i = 1;
        while (i)
        {
            cout << "Enter the int value and 0 to exit" << endl;
            cin >> i;
            if (i)
            {
                data.push_back(i);
            }
            vectorSize = data.size();
        }
    }

    void display()
    {
        cout << "Data in the vector: ";
        for (int element : data)
        {
            cout << element << " ";
        }
        cout << endl;
    }

    void searchData(int value)
    {
        bool found = false;
        for (size_t i = 0; i < data.size(); i++)
        {
            if (data[i] == value)
            {
                found = true;
                cout << "Value found in the vector ( linear search )." << endl;
                break;
            }
        }

        if (!found)
        {
            cout << "Value not found ." << endl;
        }
    }
    void binary_search(int value)
    {
        int low = 0;
        int high = data.size() - 1;
        int mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (data[mid] == value)
            {
                cout << "Value found in the vector (binary search)" << endl;
                return;
            }
            else if (data[mid] < value)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << "Value not found ." << endl;
    }

    void resize(){
        cout<<"size "<<data.size()<<endl;
        cout<<"capacity "<<data.capacity()<<endl;
        cout<<"max_size "<<data.max_size()<<endl;
        data.resize(3);
        data.shrink_to_fit();
        display();
    }
};

int main()
{
    // Search handler;

    // handler.inputData();
    // handler.display();

    // int searchValue;
    // cout << "Enter a value to search: ";
    // cin >> searchValue;
    // handler.searchData(searchValue);
    // handler.binary_search(searchValue);
    // handler.resize();

    vector<int> a={1,2,3,4};
    vector<int> b(a);
    for (int i = 0; i < 4; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<b[i]<<" ";
    }
    vector<int> c={5,6,7,8,9,10,11};
    a.swap(c);
    for (int i = 0; i < c.size(); i++)
    {
        cout<<c[i]<<" ";
    }

    return 0;
}
