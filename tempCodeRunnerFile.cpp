#include<iostream>
using namespace std ;

struct Point{
    int x;
    int y;
};

int main(){
    Point p={1,2};
    int x_coord= p.x;
    int y_coord= p.y;
    cout<<"X coordinate : "<<x_coord<<endl;
    cout<<"Y coordinate : "<<y_coord<<endl;
    return 0 ;
}