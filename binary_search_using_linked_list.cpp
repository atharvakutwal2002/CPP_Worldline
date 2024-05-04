#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class List
{
private:
    Node *head;

public:
    List()
    {
        head = nullptr;
    }
    void insertAtbeginning(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    void printLL()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node *findMiddle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void binarySearch(int target, Node *start)
    {

        if (start == NULL)
        {
            return;
        }
        Node *middle = findMiddle(start);
        if (middle->data == target)
        {
            cout << "found" << endl;
        }
        else if (middle->data < target)
        {
            binarySearch(target, middle);
        }
        else if (middle->data > target)
        {
            binarySearch(target, start);
        }
        else
        {
            cout << "Not found" << endl;
        }
    }

    void search(int target)
    {
        binarySearch(target, head);
    }
};

int main()
{
    // 1 2 3 4 5  target=4
    List myList;
    myList.insertAtbeginning(5);
    myList.insertAtbeginning(4);
    myList.insertAtbeginning(3);
    myList.insertAtbeginning(2);
    myList.insertAtbeginning(1);

    myList.printLL();
    myList.search(4);
    return 0;
}
