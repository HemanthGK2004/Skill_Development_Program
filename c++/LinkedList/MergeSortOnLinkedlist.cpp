#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Solution{
    public:
    Node* sortList(Node* head) {
        if (!head || !head->next) return head;
        Node* slow = head;
        Node* fast = head->next;
        
        // Find the middle of the list
        while (fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* mid = slow->next;
        slow->next = nullptr; // Split the list into two halves
        
        Node* left = sortList(head); // Sort the left half
        Node* right = sortList(mid); // Sort the right half
        
        return merge(left, right); // Merge the sorted halves
    }

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->data < right->data) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
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
    Node* head = new Node{4, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{1, nullptr};
    head->next->next->next = new Node{3, nullptr};

    Solution sol;
    Node* sortedHead = sol.sortList(head);
    
    cout << "Sorted List: ";
    printList(sortedHead);

    // Clean up memory (optional but good practice)
    while (sortedHead != nullptr) {
        Node* temp = sortedHead;
        sortedHead = sortedHead->next;
        delete temp;
    }

    return 0; // Return success
}
// This code implements merge sort on a linked list.
// It defines a Node structure, a Solution class with methods to sort and merge lists,
// and a main function to demonstrate the sorting functionality.