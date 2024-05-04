#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string cities[] = {"Beijing", "London", "New York"};
    const int populations[] = {21707000, 8787892, 8622698};

    for (int i = 0; i < 3; ++i)
    {
        const auto &city = cities[i];
        const auto &population = populations[i];
        cout << city << ": " << population << '\n';
    }

    return 0;
}
