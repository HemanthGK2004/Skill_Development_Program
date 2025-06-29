#include<iostream>
using namespace std;

struct  Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST{
    public:
    bool hasPathSum(Node* root, int sum) {
        if(!root) return false; // Base case: if node is null, return false
        if(!root->left && !root->right) { // If it's a leaf node
            return root->data == sum; // Check if the leaf node's value equals the remaining sum
        }
        int remainingSum = sum - root->data; // Subtract current node's value from sum
        // Recursively check left and right subtrees
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->right = new Node(1);

    BST bst; // Create an instance of BST
    int sum = 22; // Example sum to check for path
    if (bst.hasPathSum(root, sum)) {
        cout << "There is a path with sum " << sum << " in the tree." << endl;
    }
    else {
        cout << "There is no path with sum " << sum << " in the tree." << endl;
    }

    // Clean up memory (optional but good practice)
    delete root->left->left->right; // Delete node with value 2
    delete root->left->left->left; // Delete node with value 7
    delete root->left->left; // Delete node with value 11
    delete root->left; // Delete node with value 4
    delete root->right->right->right; // Delete node with value 1
    delete root->right->right; // Delete node with value 4
    delete root->right->left; // Delete node with value 13
    delete root->right; // Delete node with value 8
    delete root; // Delete root node

    return 0; // Return success
}