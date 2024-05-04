// reverse algorithm example
#include <iostream> 
#include <algorithm> 
#include <vector>    
using namespace std;

int main()
{
    std::vector<int> myvector;

    
    for (int i = 1; i < 10; ++i)
        myvector.push_back(i); 

    std::reverse(myvector.begin(), myvector.end()); 


    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        if (*it % 2 == 1)
        {
            std::cout << ' ' << *it;
            std::cout << '\n';
        }

    return 0;
}