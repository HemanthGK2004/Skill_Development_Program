// Detect cycle and Return starting index

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Solution {
public:
    Node* detectCycle(Node* head) {
        if (head == nullptr) return nullptr;
        Node* slow = head;
        Node* fast = head;
        
        // Detect cycle using Floyd's Tortoise and Hare algorithm           
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move slow by 1 step
            fast = fast->next->next;   // Move fast by 2 steps
            if (slow == fast) {
                slow = head; // Reset slow to head
                while (slow != fast) {
                    slow = slow->next; // Move slow by 1 step
                    fast = fast->next; // Move fast by 1 step
                }
                return slow; // Return the node where the cycle starts
            }
        }
        return nullptr; // No cycle detected
    }
};

int main() {
    // Create a linked list with a cycle for testing
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = head->next; // Create a cycle

    Solution sol;
    Node* cycleStart = sol.detectCycle(head);
    
    if (cycleStart) {
        cout << "Cycle detected starting at node with data: " << cycleStart->data << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    // Clean up memory (optional but good practice)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0; // Return success
}