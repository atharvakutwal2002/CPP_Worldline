#include <iostream>
#include <set>

using namespace std;

class SetClass {
private:
    set<int> s;

public:
    SetClass() {}

    void input() {
        int inp;
        cout << "Enter integer values and -1 to stop: " << endl;
        while (cin >> inp && inp != -1) {
            s.insert(inp);
        }
    }

    void display() {
        cout << "Set elements: ";
        for (const auto& elem : s) {
            cout << elem << " ";
        }
        cout << endl;
    }

    void search(int searchElement) {
        auto it = s.find(searchElement);
        if (it != s.end()) {
            cout << searchElement << " found" << endl;
        } else {
            cout << searchElement << " not found" << endl;
        }
    }

    void deleteEle(int delEle) {
        auto it = s.find(delEle);
        if (it != s.end()) {
            s.erase(it);
            cout << delEle << " deleted" << endl;
        } else {
            cout << delEle << " not found, deletion failed" << endl;
        }
    }
};

int main() {
    SetClass s;
    s.input();
    s.display();

    int searchEle;
    cout << "Enter the element to search: ";
    cin >> searchEle;
    s.search(searchEle);

    int delEle;
    cout << "Enter the element to delete: ";
    cin >> delEle;
    s.deleteEle(delEle);

    s.display();

    return 0;
}
