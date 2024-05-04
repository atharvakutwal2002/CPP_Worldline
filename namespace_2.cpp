#include <iostream>
using namespace std;

namespace a {
    class IntClass {
    public:
        int value = 100;
    };
}

namespace b {
    class FloatClass {
    public:
        float value = 7.56;
    };
}

int main() {
    using namespace a; 
    using namespace b; 

    IntClass objInt;
    FloatClass objFloat;

    cout << " a->> " << objInt.value << endl;
    cout << " b->> " << objFloat.value << endl;
    

    return 0;
}
