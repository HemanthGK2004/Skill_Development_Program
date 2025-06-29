//Minimum distance between BST nodes
#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class solution {
public:
    int minDiff = INT_MAX; // Initialize minimum difference to maximum integer value
    int prev = -1; // Previous node value, initialized to -1
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return; // Base case: if node is null, return

        inorderTraversal(root->left); // Traverse left subtree

        if (prev != -1) { // If prev is not -1, calculate difference
            minDiff = min(minDiff, root->val - prev); // Update minimum difference
        }
        prev = root->val; // Update previous node value

        inorderTraversal(root->right); // Traverse right subtree
    }

    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root); // Start inorder traversal from root
        return minDiff; // Return the minimum difference found
    }
};

int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    solution sol; // Create an instance of the solution class
    int minDiff = sol.getMinimumDifference(root); // Get the minimum difference
    cout << "Minimum difference between BST nodes: " << minDiff << endl; // Print the result
}