#include <iostream>

using namespace std;

template <typename... Args>
int fact(Args... args)
{
    return (1 * ... * args);
}

int main()
{
    int nfact = fact(1, 2, 3, 4);
    int rfact = fact(1, 2, 3);
    int nrfact = fact(1, 2, 3);
    cout << "N!= " << nfact << "\n"
         << "R!= " << rfact << "\n"
         << "N-R!= " << nrfact << "\n";
    cout << "nPr = " << nfact / nrfact << "\n";
    cout << "nCr = " << nfact / (rfact * nrfact) << "\n";
    return 0;
}