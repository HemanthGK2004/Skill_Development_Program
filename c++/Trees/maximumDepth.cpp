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
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)return 0;
        int leftDepth = maxDepth(root->left); // Recursively find depth of left subtree
        int rightDepth = maxDepth(root->right); // Recursively find depth of right subtree
        return max(leftDepth, rightDepth) + 1; // Return the maximum depth of
    }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    int depth = sol.maxDepth(root); // Calculate the maximum depth of the tree
    cout << "Maximum depth of the binary tree: " << depth << endl; // Print the result

    // Clean up memory (optional but good practice)
    delete root->left->left; // Delete node with value 4
    delete root->left->right; // Delete node with value 5
    delete root->left; // Delete node with value 2
    delete root->right; // Delete node with value 3
    delete root; // Delete root node

    return 0; // Return success
}