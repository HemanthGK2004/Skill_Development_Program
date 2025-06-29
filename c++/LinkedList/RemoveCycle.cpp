#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        if(!head||!head->next)return;
        Node* slow=head;
        Node* fast =head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(slow==fast){
            slow=head;
            if(slow==fast){
                while(fast->next!=slow){
                    fast=fast->next;
                }
                fast->next=nullptr;
                return;
            }
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=nullptr;
        }
    }
};
// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with a loop for testing
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Create a loop

    Solution sol;
    sol.removeLoop(head);

    cout << "Linked list after removing loop: ";
    printList(head); // Should print 1 2 3 4
    
    // Clean up memory (optional but good practice) 
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0; // Return success
}