// Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <iostream>

struct Node{
    int data;
    Node* next;
    
    Node(int x) : data(x), next(nullptr) {}
};
class Solution {
    public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k <= 1) return head;

        Node* temp = head;
        
        // Count the number of nodes in the linked list
        for(int i =0;i<k; i++) {
            if(temp==NULL)return head;
            temp = temp->next;
        }
        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        int count = 0;
        
        // Reverse k nodes
        while(count < k) {
            next = current->next; // Store the next node
            current->next = prev; // Reverse the link
            prev = current;       // Move prev to current
            current = next;
            count++;
        }
        
        // If there are more nodes to reverse, recursively call the function
        if (next) {
            head->next = reverseKGroup(next, k);
        }
        // Return the new head of the reversed group
        return prev;
    }
};

// Utility function to print the linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution sol;
    int k = 2;
    Node* reversedHead = sol.reverseKGroup(head, k);

    std::cout << "Reversed linked list in groups of " << k << ": ";
    printList(reversedHead);

    // Clean up memory (optional but good practice)
    while (reversedHead != nullptr) {
        Node* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0; // Return success
}