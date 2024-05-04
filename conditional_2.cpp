#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the character "<<endl;
    char ch;
    cin>>ch;
    if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
    {
        cout<<"Entered char is a vowel"<<endl;
    }
    else{
        cout<<"Entered char is not a vowel"<<endl;
    }
    
}