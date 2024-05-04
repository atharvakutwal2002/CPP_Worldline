#include <iostream>
#include <memory>
using namespace std;
class A
{
public:
    void show() { cout << "A::show()" << endl; }
};
int main()
{
    shared_ptr<A> p1(new A);
    p1->show();
    cout << p1.get() << endl;
    shared_ptr<A> p2(p1);
    p1->show();
    p2->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    shared_ptr<A> p3(new A);
    p1->show();
    p2->show();
    p3->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p3.get() << endl;
    shared_ptr<A> p4;
    p1->show();
    p2->show();
    p3->show();
    p4->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p3.get() << endl;
    cout << p4.get() << endl;

    return 0;
}
