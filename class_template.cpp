#include<bits/stdc++.h>
using namespace std;

template<class T , int size>
class A{
    public:
    T arr[size];
    void insert(){
        int i=1;
        for (int j = 0; j < size; j++)
        {
            arr[j]=i;
            i++;
        }
        
    }

    void display(){
        for (int j = 0; j < size; j++)
        {
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    A<int,10> t1;
    t1.insert();
    t1.display();
    A<float,5> t2;
    t2.insert();
    t2.display();
    A<char,7>t3;
    t3.insert();
    t3.display();
    return 0;
}