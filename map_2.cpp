#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{

    map<int, string> studentMap{{1,"Atharva"},{2,"Shrutika"},{3,"Vaishnavi"},{4,"Vinay"},{5,"Max"},{6,"Anil"}};

    for (auto it = studentMap.begin(); it != studentMap.end(); ++it)
    {
        cout << "Roll  " << it->first << " Student " << it->second << endl;
    }
    cout<<"after deleting "<<endl;
    studentMap.erase(studentMap.find(2),studentMap.find(4));
    for (auto it = studentMap.begin(); it != studentMap.end(); ++it)
    {
        cout << "Roll  " << it->first << " Student " << it->second << endl;
    }
    cout<<"after clear() the map is empty"<<endl;
    studentMap.clear();
    for (auto it = studentMap.begin(); it != studentMap.end(); ++it)
    {
        cout << "Roll  " << it->first << " Student " << it->second << endl;
    }
    return 0;
}
