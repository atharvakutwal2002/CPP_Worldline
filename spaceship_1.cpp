#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 9;
    auto ans = a <=> b;
    if (ans < 0) {
        cout << "a < b";
    } else if (ans == 0) {
        cout << "a = b";
    } else {
        cout << "a > b";
    }

    return 0;
}
