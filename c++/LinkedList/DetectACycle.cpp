// Detect a loop in a linked list and remove it if found
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class solution {
public:
    bool hasCycle(Node* head) {
        if (head == nullptr) return false;
        Node* slow = head;
        Node* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;          // Move slow by 1 step
            fast = fast->next->next;   // Move fast by 2 steps
            if (slow == fast) {
                return true; // Cycle detected
            }
        }
        return false; // No cyc/ Return the node where the cycle starts
    }
};

int main() {
    // Create a linked list with a cycle for testing
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Create a cycle

    solution sol;
    if (sol.hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
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