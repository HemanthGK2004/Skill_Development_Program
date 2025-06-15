//single linked list implementation
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SingleLinkedList {
private:
    Node* head;

public:
    SingleLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    ~SingleLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    SingleLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Single Linked List: ";
    list.display();

    return 0;
}
// This code defines a simple single linked list with insert and display functionalities.
// The destructor ensures that all allocated memory is freed when the list is destroyed.