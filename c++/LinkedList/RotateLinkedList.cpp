// rotate a linked list by k nodes

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
class Solution {
public:
    Node* rotate(Node* head, int k) {
        if (!head ||!head->next|| k <= 0) return head; // If the list is empty or k is non-positive
        Node* temp = head;
        int length = 1; // Initialize length to 1 for the head node

        while (temp->next) {
            temp = temp->next; // Traverse to the end of the list
            length++;
        }

        k = k % length; // Handle cases where k is greater than the length of the list
        if (k == 0) return head; // If k is 0 after modulo, no rotation needed

        temp->next = head; // Connect the end of the list to the head to make it circular
        int stepsToNewHead = length - k; // Calculate the number of steps to the new head

        Node* newTail = head;// Initialize newTail to head
        for (int i = 0; i < stepsToNewHead - 1; i++) {
            newTail = newTail->next; // Move to the new tail node
        }

        Node* newHead = newTail->next; // The new head is the next node after the new tail
        newTail->next = nullptr; // Break the circular link to form a proper list

        return newHead; // Return the new head of the rotated list
        
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    Solution sol;
    int k = 2;

    Node* rotatedHead = sol.rotate(head, k);
    cout << "Rotated List: ";
    printList(rotatedHead); // Should print 4 5 1 2 3
    
    // Clean up memory (optional but good practice)
    while (rotatedHead != nullptr) {
        Node* temp = rotatedHead;
        rotatedHead = rotatedHead->next;
        delete temp;
    }
    
    return 0; // Return success
}
// This code rotates a linked list by k nodes and prints the rotated list.
// It handles cases where k is greater than the length of the list and ensures proper memory management.