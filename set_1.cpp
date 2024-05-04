#include<iostream>
#include<set>
using namespace std;
int main()
{
    // Empty Set
    set<int> set1; //set1={} -> ascending order
    // Empty Set - Decreasing Order
    set<int, greater<int>> set2; //set2={}
    // Set with values
    set<int, greater<int>> set3 = {6, 10, 5, 1};
    // set3 = {10, 6, 5, 1}
    // Initialize Set using other set
    set<int, greater<int>> set4(set3);
    // set4 = {10, 6, 5, 1} 
    // Initializing a set from array
    int arr[] = {10, 4, 5, 61,22,33,44};
    set<int> set5(arr, arr+4);  // Since the array has four elements, thus arr+4 
     // Defining iterator for the set
    set<int> :: iterator it;
    //Printing a set using for loop – (1)
    cout<<"Set3 \n";
    for (auto it = set3.begin(); it!=set3.end();it++)
    {
        cout<<endl<<*it;
    }
    ///Printing a set using for loop – (1)
    cout<<"Set4 \n";
    for (auto it = set4.begin(); it!=set4.end();it++)
    {
        cout<<endl<<*it;
    }//Printing a set using for loop – (1)
    cout<<"Set5 \n";
    for (auto it = set5.begin(); it!=set5.end();it++)
    {
        cout<<endl<<*it;
    }
    return 1;
}