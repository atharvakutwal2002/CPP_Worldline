#include<bits/stdc++.h>
using namespace std ;

template <typename T > class guess{
    T i ;
    T j ;
    string input;
    public:
    guess(T i , T j){
        this->i=i;
        this->j=j;
    }
    void startGame(){
        cout<<"Start guessing value between "<<i<<" and "<<j<<endl;
        cout<<"Options are less , more , yes "<<endl;
        while (true)
        {
            
            T mid= (i+j)/2;
            cout<<"Is the value "<<mid<<endl;
            cin>>input;
            if(input=="less"){
                j=mid-1;
            }else if(input=="more"){
                i=mid+1;
            }else if(input=="yes"){
                cout<<"Guessed the value right !"<<endl;
                return ;
            }else{
                cout<<"Input is invalid"<<endl;
            }

        }
        
    }

};

int main(){
    guess<int> g1(1,100);
    g1.startGame();
    guess<char> g2('a','z');
    g2.startGame();

    return 0;
}