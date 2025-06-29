#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    bool isSameTree(Node* p, Node* q) {
        if (!p && !q) return true; // Both nodes are null, trees are the same
        if (!p || !q) return false; // One node is null, trees are not the same
        if (p->data != q->data) return false; // Values must match
        // Check left and right subtrees recursively
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution solution;

    // Create two identical trees
    Node* tree1 = new Node(1);
    tree1->left = new Node(2);
    tree1->right = new Node(3);

    Node* tree2 = new Node(1);
    tree2->left = new Node(2);
    tree2->right = new Node(3);

    if (solution.isSameTree(tree1, tree2)) {
        cout << "The two trees are the same." << endl;
    } else {
        cout << "The two trees are not the same." << endl;
    }

    // Clean up memory (optional but good practice)
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0; // Return success
}