#include<iostream>
#include<vector>
using namespace std;

class Node{
    int data;
    Node* next;
}
class Solution {
public:
    Node* middleOfLinkedList(Node* head) {
        if (head == nullptr) return nullptr; // Handle empty list

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next; // Move slow by 1 step
            fast = fast->next->next; // Move fast by 2 steps
        }
        return slow; // Slow will be at the middle node
    }
};

int main() {
    // Example usage of the middleOfLinkedList function
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution solution;
    Node* middleNode = solution.middleOfLinkedList(head);

    if (middleNode != nullptr) {
        cout << "Middle node data: " << middleNode->data << endl; // Output the middle node's data
    } else {
        cout << "The linked list is empty." << endl; // Handle empty list case
    }

    // Clean up memory (optional but good practice)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0; // Return success
}
// This code defines a function to find the middle node of a singly linked list using the slow and fast pointer technique.
// The main function demonstrates how to create a linked list, call the function, and print the middle node's data.