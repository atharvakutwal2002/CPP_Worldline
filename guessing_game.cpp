#include <bits/stdc++.h>
using namespace std;

int startGame()
{
    int i = 0;
    int j = 100;
    int guess;

    string input;
    cout << j << endl;
    cout << "If the prompted number is corrected type yes , lesser of more depending " << endl;

    while (true)
    {
        int guess = i + j / 2;
        cout << "Is the guesses number " << guess << " correct " << endl;
        cin >> input;
        if (input == "lesser")
        {
            j = guess - 1;
        }
        else if (input == "more")
        {
            i = guess + 1;
        }
        else if (input == "yes")
        {
            cout << "Yeahh boy ! Done it right " << endl;
            break;
        }
        else
        {
            cout << "Options are lesser , more , yes " << endl;
        }
    }
}

int main()
{
    startGame();
    return 0;
}