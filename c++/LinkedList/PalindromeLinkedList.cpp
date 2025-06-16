// Check whether a linked list is a palindrome
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
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next; // Store the next node
            current->next = prev; // Reverse the link
            prev = current;       // Move prev to current
            current = next;       // Move to the next node
        }
        return prev; // Return the new head of the reversed list
    }

    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        Node* slow = head;
        Node* fast = head;

        // Find the middle of the linked list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list
        Node* secondHalf = reverse(slow);

        // Compare the first half and the reversed second half
        Node* firstHalf = head;

        while (secondHalf) {
            if (firstHalf->data != secondHalf->data) {
                return false; // Not a palindrome
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true; // Is a palindrome
    }
};

// Example usage
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    Solution solution;
    bool result = solution.isPalindrome(head);
    cout << "Is the linked list a palindrome? " << (result ? "Yes" : "No") << endl;

    // Clean up memory (optional but good practice)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0; // Return success
}
// This code checks whether a linked list is a palindrome by reversing the second half of the list and comparing it with the first half.