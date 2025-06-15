#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Solution {
public:
    Node* mergeTwoLists(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->data < l2->data) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main() {
    // Create first sorted linked list: 1 -> 3 -> 5
    Node* l1 = new Node{1, new Node{3, new Node{5, nullptr}}};

    // Create second sorted linked list: 2 -> 4 -> 6
    Node* l2 = new Node{2, new Node{4, new Node{6, nullptr}}};

    Solution sol;
    Node* mergedList = sol.mergeTwoLists(l1, l2);

    // Print merged linked list
    while (mergedList) {
        cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    // Clean up memory (optional but good practice)
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
// This code merges two sorted linked lists and prints the merged list.
// It uses recursion to merge the lists in a sorted manner.