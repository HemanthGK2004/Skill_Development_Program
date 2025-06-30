#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BFS {
public:
    void levelOrderTraversal(Node* root) {
        if (root == nullptr) return; // Base case: if root is null, return
        queue<Node*> q; // Create a queue to hold nodes at each level
        q.push(root); // Start with the root node
        while (!q.empty()) {
            Node* current = q.front(); // Get the front node
            q.pop(); // Remove it from the queue
            cout << current->data << " "; // Print the current node's data

            // Add left child to the queue if it exists
            if (current->left != nullptr) {
                q.push(current->left);
            }
            // Add right child to the queue if it exists
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << endl; // New line after traversal
    }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    BFS bfs; // Create an instance of BFS class
    cout << "Level Order Traversal: ";
    bfs.levelOrderTraversal(root); // Perform level order traversal

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