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
    unique_ptr<A> p1(new A);
    p1->show();
    cout << p1.get() << endl;
    unique_ptr<A> p2; // unique_ptr<A> p2(p1) - error

    p1->show();
    p2->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    unique_ptr<A> p3(new A);
    p1->show();
    p2->show();
    p3->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p3.get() << endl;
    unique_ptr<A> p4;
    p1->show();
    p2->show();
    p3->show();
    p4->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p3.get() << endl;
    cout << p4.get() << endl;
    // shared_ptr<A> p5(new A);
    // auto_ptr<A> p6(p5);

    return 0;
}