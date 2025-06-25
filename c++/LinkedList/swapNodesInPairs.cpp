// Swap Nodes in Pairs in a Linked List

#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};
class Solution {
public:
    Node* swapPairs(Node* head) {
        if (!head || !head->next) return head; // If the list is empty or has only one node

        Node* dummy = new Node(0); // Create a dummy node to simplify the swapping process
        dummy->next = head;
        Node* prev = dummy;

        while (prev->next && prev->next->next) {
            Node* first = prev->next; // First node in the pair
            Node* second = first->next; // Second node in the pair

            // Swap the nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev to the next pair
            prev = first;
        }
        Node* newHead = dummy->next; // The new head of the swapped list
        delete dummy; // Clean up the dummy node
        return newHead; // Return the new head of the swapped list
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
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    
    Solution sol;
    Node* swappedHead = sol.swapPairs(head);
    cout << "Swapped List: ";
    printList(swappedHead);

    // Clean up memory (optional but good practice)
    while (swappedHead != nullptr) {
        Node* temp = swappedHead;
        swappedHead = swappedHead->next;
        delete temp;
    }
    
    return 0; // Return success
}