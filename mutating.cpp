#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    // reverse(a+2, a+5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << a[i] << " ";
    // }
    int reverse_cp[5];
    reverse_copy(a, a+5, reverse_cp);
    for(int x: reverse_cp){
        cout<<x<<" ";
    }

    return 0;
}