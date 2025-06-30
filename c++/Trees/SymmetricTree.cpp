#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class SymmetricTree {
public:
    bool isMirror(Node* t1, Node* t2) {
        if(!t1 && !t2) return true; // Both nodes are null, symmetric
        if(!t1 || !t2) return false;
        if(t1->data != t2->data) return false; // Values must match
        // Check if left subtree of t1 is a mirror of right subtree of t2 and vice versa
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
    bool isSymmetric(Node* root) {
        if(!root) return true;
        return isMirror(root, root);
    }
};

int main() {
    SymmetricTree treeChecker;
    
    // Create a symmetric tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if(treeChecker.isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    // Clean up memory (optional but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0; // Return success
}