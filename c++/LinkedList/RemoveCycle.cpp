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