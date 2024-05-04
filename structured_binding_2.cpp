#include <bits/stdc++.h>
#include <map>
using namespace std;
int main()
{
    const std::map<std::string, int> mapCityPopulation{
        {"Beijing", 21707000},
        {"London", 8787892},
        {"New York", 8622698}};
    for (const auto &[city,population] : mapCityPopulation)
        std::cout << city << ": " << population << '\n';
}