#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val,Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};
class Solution {
    public:
    bool hasCycle(Node* head) {
        if (head == nullptr) return false;
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move slow by 1 step
            fast = fast->next->next;   // Move fast by 2 steps
            if (slow == fast) {
                removeCycle(head, slow);
                return true; // Cycle detected
            }
        }
        return false; // No cycle
    }
    private:
    void removeCycle(Node* head, Node* meetingPoint) {
        Node* slow = head;
        Node* fast = meetingPoint;

        // Move slow to the head and keep fast at the meeting point
        while (slow->next != fast->next) {
            slow = slow->next; // Move slow by 1 step
            fast = fast->next; // Move fast by 1 step
        }
        fast->next = nullptr; // Remove the cycle
    }
};
int main() {
    // Create a linked list with a cycle for testing
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Create a cycle

    Solution sol;
    if (sol.hasCycle(head)) {
        cout << "Cycle detected and removed from the linked list." << endl;
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

