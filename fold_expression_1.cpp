#include <iostream>
template <typename... T>
auto average(T... t)
{
    int sum = (t + ...);
    std::cout << sum << "\n";
    return (t + ...) / sizeof...(t);
}
int main()
{
    std::cout << average(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
}