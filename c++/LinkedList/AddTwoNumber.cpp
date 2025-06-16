#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val,Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

class Solution {
public:
    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* dummy = new Node(0);
        Node* current = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->data;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->data;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new Node(sum % 10);
            current = current->next;
        }

        return dummy->next; // Return the next node to skip the dummy head
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
    Node* l1 = new Node{2, new Node{4, new Node{3, nullptr}}}; // Represents 342
    Node* l2 = new Node{5, new Node{6, new Node{4, nullptr}}}; // Represents 465
    
    Solution sol;
    Node* result = sol.addTwoNumbers(l1, l2);
    cout << "Sum List: ";
    printList(result); // Should print 7 -> 0 -> 8 (represents 807)
    
    // Clean up memory (optional but good practice)
    while (result != nullptr) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }
    while (l1 != nullptr) {
        Node* temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2 != nullptr) {
        Node* temp = l2;
        l2 = l2->next;
        delete temp;
    }
    
    return 0; // Return success
}