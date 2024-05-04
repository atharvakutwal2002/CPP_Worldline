#include <iostream>

using namespace std;

int a = 10;

namespace mynamespace {

int& fun()

{

    return a;

}

}

int main()

{

    mynamespace::fun() = 20;

    cout << a << endl;

    return 0;

}