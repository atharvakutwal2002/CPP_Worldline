#include <iostream>
using namespace std;

namespace first
{
    int add(int a, int b)
    {
        return a + b;
    }
}

namespace second
{
    int add(int a, int b)
    {
        return a + b;
    }
}

int main()
{
    cout << "Hello world!" << endl;

    cout << "Value of a for first namespace " << first::add(2,4) << endl;
    cout << "Value of a for second namespace " << second::add(5,6) << endl;
    return 0;
}
