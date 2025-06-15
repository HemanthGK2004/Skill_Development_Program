#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
class Solution {
    public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* curr = head;
        while(curr) {
            if(curr->child) {
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;
                while(curr->next) {
                    curr = curr->next;
                }
                if(next) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

int main() {
    // Example usage
    Node* head = new Node{1, nullptr, nullptr, nullptr};
    head->next = new Node{2, head, nullptr, nullptr};
    head->next->child = new Node{3, nullptr, nullptr, nullptr};
    head->next->child->next = new Node{4, head->next->child, nullptr, nullptr};

    Solution sol;
    Node* flattenedList = sol.flatten(head);

    // Print flattened linked list
    Node* curr = flattenedList;
    while(curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    // Clean up memory (optional but good practice)
    while (flattenedList != nullptr) {
        Node* temp = flattenedList;
        flattenedList = flattenedList->next;
        delete temp;
    }

    return 0; // Return success
}