#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;

    Node(int x) : data(x), next(nullptr), bottom(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* root) {
        if (!root || !root->next) return root;
        // Recursively flatten the next list
        root->next = flatten(root->next);

        // Merge current list with the flattened next list
        return mergeTwoLists(root, root->next);
    }

private:
    Node* mergeTwoLists(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        Node* result;
        if (a->data < b->data) {
            result = a;
            result->bottom = mergeTwoLists(a->bottom, b);
        } else {
            result = b;
            result->bottom = mergeTwoLists(a, b->bottom);
        }
        result->next = nullptr; // Remove next pointer in the final flattened list
        return result;
    }
};

// Utility function to print the flattened linked list
void printFlattenedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main() {
    /*
    Constructing the following 2D list:
    5 -> 10 -> 19 -> 28
    |     |     |     |
    7     20    22    35
    |           |     |
    8           50    40
    |                 |
    30                45
    */

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution sol;
    Node* flatHead = sol.flatten(head);

    cout << "Flattened list: ";
    printFlattenedList(flatHead);

    // Clean-up memory: ideally you'd recursively delete, skipped for brevity
    return 0;
}
