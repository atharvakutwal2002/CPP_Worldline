#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{

    map<int, string> studentMap;

    studentMap[1] = "Atharva ";
    studentMap[2] = "Shrutika";
    studentMap[3] = "Vaishnavi";
    studentMap[4] = "Vinay";
    studentMap[5] = "Vinay";
    for (auto it = studentMap.begin(); it != studentMap.end(); ++it)
    {
        cout << "Roll  " << it->first << " Student " << it->second << endl;
    }
    cout<<studentMap[4];
    map<int,string> ::iterator iter;
    iter = studentMap.find(3);
    cout<<iter->second<<endl;
    return 0;
}
