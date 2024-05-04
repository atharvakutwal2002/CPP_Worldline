#include <iostream>
using namespace std;

constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

int main() {
    constexpr int num = 3;
    

    if constexpr (num > 0) { 
        constexpr int result = factorial(num);
        cout << "Factorial of " << num << " is " << result << endl;
    } else {
        cout << "Factorial of " << num << " is undefined" << endl; 
    }

    return 0;
}
