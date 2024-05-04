#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int reg_no;
    string name;
    Node *next;
    Node(int data, string name)
    {
        this->next = nullptr;
        this->reg_no = data;
        this->name = name;
    }
};

class linkedList
{
public:
    Node *head;
    linkedList()
    {
        head = nullptr;
    }
    void addStudent(int reg, string name)
    {
        Node *temp = new Node(reg, name);
        temp->next = head;
        head = temp;
    }
    void searchStudent(int reg)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->reg_no == reg)
            {
                cout << "Student with reg no " << reg << " found . Name is " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student with reg no " << reg << " not found ." << endl;
    }
    void deleteStudent(int reg)
    {
        Node *temp;
        if (head->reg_no == reg)
        {
            temp = head->next;
            delete head;
            head = temp;
            return;
        }
        Node *slow = head;
        Node *fast = head->next;
        while (fast != nullptr)
        {
            if (fast->reg_no == reg)
            {
                slow->next = fast->next;
                delete fast;
            }
            slow = slow->next;
            fast = fast->next;
        }
    }
    void printDatabase()
    {
        Node *temp = head;
        cout<<"The student database ...."<<endl;
        while (temp != nullptr)
        {
            cout << " reg no " << temp->reg_no << "; name : " << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    linkedList data;
    int reg_no ;
    string name ;
    cout<<"Enter reg no and name of the student and -1 to stop "<<endl;
    while (cin>> reg_no && reg_no!=-1)
    {
        cin>>name;
        data.addStudent(reg_no, name);   
    }
    
    data.printDatabase();
    int searchNo;
    cout<<"Enter the reg no to search from the database  "<<endl;
    cin>>searchNo;
    data.searchStudent(searchNo);
    cout<<endl;
    int delNo;
    cout<<"Enter the reg no to delete from the database  "<<endl;
    cin>>delNo;
    data.deleteStudent(delNo);
    cout<<endl;
    data.printDatabase();
    return 0;
}