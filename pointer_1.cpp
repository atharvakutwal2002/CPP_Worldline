#include <iostream>
using namespace std;

int main()
{
    // int a =10 , *ptr;
    // ptr = & a;

    // cout<<++*ptr<<endl;
    // cout<<(*ptr)++<<endl;
    // int arr[]={2,3,4,5,6};
    // cout<<sizeof(arr)<<endl;
    // cout<<sizeof(*arr)<<endl;
    // cout<<sizeof(&arr[0])<<endl;

    // int a[2][3][4] = {
    //     {1, 2, 3, 4,
    //      5, 6, 7, 8,
    //      9, 1, 1, 2},
    //     {2, 1, 4, 7,
    //      6, 7, 8, 9,
    //      0, 0, 0, 0}};
    // printf("\n%d %d %d %d", a, *a, **a, ***a);

    // int a[3][4]={
    //     1,2,3,4,
    //     5,6,7,8,
    //     9,10,11,12
    // };
    // printf("\n%u %u %u",a[0]+1, *(a[0]+1),*(*(a+0)+1));
    // cout<<endl;

    // printf("%c" ,7["chandramohan"]);

    // int * var;
    // var =new int;
    // *var=50;
    // cout<<*var;

    int *arr{new int[6]{1,2,3,4,5,6}};
    cout<<"Array elements"<<endl;
    for (int i = 0; i < 6; i++)
    {
        
        cout<<arr[i]<<" ";
    }
    

    return 0;
}