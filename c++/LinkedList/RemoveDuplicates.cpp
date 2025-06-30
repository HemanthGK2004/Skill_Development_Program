// Remove duplicates from a sorted linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        if (!head) return head; // If the list is empty, return null

        Node* current = head;
        while (current->next) {
            if (current->data == current->next->data) {
                Node* temp = current->next; // Store the next node
                current->next = current->next->next; // Skip the duplicate node
                delete temp; // Free memory of the duplicate node
            } else {
                current = current->next; // Move to the next node
            }
        }
        return head; // Return the modified list
    }
};

// Utility function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{1, nullptr};
    head->next->next = new Node{2, nullptr};
    head->next->next->next = new Node{3, nullptr};
    head->next->next->next->next = new Node{3, nullptr};

    Solution sol;
    Node* modifiedHead = sol.removeDuplicates(head);
    
    cout << "Modified List: ";
    printList(modifiedHead); // Print the modified linked list

    // Clean up memory (optional but good practice)
    while (modifiedHead != nullptr) {
        Node* temp = modifiedHead;
        modifiedHead = modifiedHead->next;
        delete temp;
    }

    return 0; // Return success
}