#include <iostream>

namespace FirstSpace
{
    int value1 = 90;
    int value2 = 30;
}

namespace SecondSpace
{
    int findMaximum(int x, int y)
    {
        return (x > y) ? x : y;
    }
}

int main()
{
    using namespace FirstSpace;
    using namespace SecondSpace;
    using namespace std;

    cout << "Values of value1 and value2: " << FirstSpace::value1 << " and " << FirstSpace::value2 << endl;
    cout << "Maximum value: " << findMaximum(FirstSpace::value1, FirstSpace::value2) << endl;

    return 0;
}
