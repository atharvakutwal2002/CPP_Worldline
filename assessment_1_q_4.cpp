#include <iostream>
using namespace std;

struct Node
{
    int key;
    string data;
    Node *prev;
    Node *next;

    Node(int k, string d)
    {
        this->key = k;
        this->data = d;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoubleLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoubleLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int countNodes()
    {
        return size;
    }

    void traverseForward()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->key << "->" << current->data <<endl; 
            current = current->next;
        }
        
    }

    void traverseBackward()
    {
        Node *current = tail;
        while (current != nullptr)
        {
            cout << current->key << "->" << current->data <<endl; 
            current = current->prev;
        }
        
    }

    void insertLast(int key, string data)
    {
        Node *newNode = new Node(key, data);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insertAfterKth(int k, int key, string data)
    {
        if (k < 0 || k >= size)
        {
            cout << "Invalid position\n";
            return;
        }

        Node *newNode = new Node(key, data);
        if (k == size - 1)
        {
            insertLast(key, data);
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < k; ++i)
            {
                current = current->next;
            }
            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
            size++;
        }
    }

    void deleteLast()
    {
        if (isEmpty())
        {
            cout << "List is empty, nothing to delete\n";
            return;
        }

        if (size == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        size--;
    }

    void deleteFirst()
    {
        if (isEmpty())
        {
            cout << "List is empty, nothing to delete\n";
            return;
        }

        if (size == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        size--;
    }

    void deleteByKey(int key)
    {
        if (isEmpty())
        {
            cout << "List is empty, nothing to delete\n";
            return;
        }

        Node *current = head;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (current == head)
                    deleteFirst();
                else if (current == tail)
                    deleteLast();
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    size--;
                }
                cout << "Node with key " << key << " deleted successfully\n";
                return;
            }
            current = current->next;
        }
        cout << "Node with key " << key << " not found\n";
    }
};

int main()
{
    DoubleLinkedList mylist;

    cout << "Is list is empty: " << (mylist.isEmpty() ? "Yes" : "No") << endl;

    mylist.insertLast(1, "Atharva");
    mylist.insertLast(2, "Shrutika");
    mylist.insertLast(3, "Vaishnavi");

    cout << "Total number of nodes: " << mylist.countNodes() << endl;

    cout << "Forward traversal: "<<endl;
    mylist.traverseForward();

    cout << "Backward traversal: "<<endl;
    mylist.traverseBackward();

    mylist.insertAfterKth(1, 4, "Jennie");

    cout << "List after insertion: "<<endl;
    mylist.traverseForward();

    mylist.deleteLast();
    cout << "List after deleting last node: "<<endl;
    mylist.traverseForward();

    mylist.deleteFirst();
    cout << "Lisst after deleting first node: "<<endl;
    mylist.traverseForward();

    mylist.deleteByKey(2);
    cout << "List after deleting node with key 2: "<<endl;
    mylist.traverseForward();

    return 0;
}
