#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
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
    void addNode(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void traverseAndDelete(int M, int N)
    {
        if (head == nullptr)
            return;

        Node *current = head;
        Node *temp;

        while (current != nullptr)
        {

            for (int i = 1; i < M && current != nullptr; i++)
                current = current->next;

            if (current == nullptr)
                return;

            temp = current->next;

            for (int i = 1; i <= N && temp != nullptr; i++)
            {
                Node *nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }

            current->next = temp;
            current = temp;
        }
    }
}

;

int main()
{
    linkedList li;

    cout << "Enter the int value and -1 to stop : " << endl;
    int nodeVal;

    while (cin >> nodeVal && nodeVal != -1)
    {
        li.addNode(nodeVal);
    }
    int M, N;
    cout << "Enter M : " << endl;
    cin >> M;
    cout << "Enter N : " << endl;
    cin >> N;
    cout << "Linked List before performing deletion operation is : " << endl;
    li.printList();
    li.traverseAndDelete(M, N);
    cout << "Linked List after performing deletion operation is : " << endl;
    li.printList();

    return 0;
}
