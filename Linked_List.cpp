#include <iostream>
using namespace std ;


class Node {
public:
    int data;
    Node* next;

   
    Node(int value) : data(value), next(nullptr) {}
};


class LinkedList {
private:
    Node* head; 

public:
    
    LinkedList() : head(nullptr) {}

    
    void insertAtBeginning(int value) {
        
        Node* newNode = new Node(value);

        
        newNode->next = head;

       
        head = newNode;
    }

    
    void printLinkedList() {
        Node* current = head; 

        
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next; 
        }

        cout << std::endl;
    }
};


int main() {
    
    LinkedList myList;

    
    myList.insertAtBeginning(3);
    myList.insertAtBeginning(7);
    myList.insertAtBeginning(11);

    
    
    myList.printLinkedList();

    return 0;
}
