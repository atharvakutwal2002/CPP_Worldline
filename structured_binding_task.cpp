// #include <bits/stdc++.h>
// using namespace std;

// struct Point
// {
//     int x, y;

//     Point() : x(0), y(0)
//     {
//     }
    
//         Point(int x, int y) : x(x), y(y)
//     {
//     }

//     auto operator()()
//     {
        
//             return make_tuple(x, y);
//     }
// };

// int main()
// {
//     Point p = {1, 2};
//     int x_coord, y_coord;
//     tie(x_coord, y_coord) = p();
//     cout << "X Coordinate : " << x_coord << endl;
//     cout << "Y Coordinate : " << y_coord << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;

    Point() : x(0), y(0)
    {
    }
    Point(int x, int y) : x(x), y(y)
    {
    }
    auto operator()()
    {
            return make_tuple(x, y);
    }
};

int main()
{
    Point p1 = {1, 2};
    int x_coord, y_coord;
    tie(x_coord, y_coord) = p1();
    cout << "Coordinates of p1 : " << x_coord <<" "<< y_coord<< endl;
    Point p2 ;
    int x_coord2, y_coord2;
    tie(x_coord2, y_coord2) = p2();
    cout << "Coordinates of p2 : " << x_coord2<<" "<<y_coord2 << endl;
    Point p3= p1 ;
    int x_coord3, y_coord3;
    tie(x_coord3, y_coord3) = p3();
    cout << "Coordinates of p3 : " << x_coord3<<" "<<y_coord3 << endl;
    return 0;
}