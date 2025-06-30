#include <iostream>
#include <climits> // For LONG_MIN and LONG_MAX
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    bool isValidBST(Node* node, long minVal, long maxVal) {
        if (node == nullptr) return true;
        if (node->data <= minVal || node->data >= maxVal) return false;
        return isValidBST(node->left, minVal, node->data) &&
            isValidBST(node->right, node->data, maxVal);
    }
    void findMinMax(Node* node){
        if(node == nullptr) return;
        while(node->left != nullptr) {
            node = node->left; // Traverse to the leftmost node
        }
        cout << "Minimum value in the BST: " << node->data << endl;
        node = root; // Reset to root to find maximum
        while(node->right != nullptr) {
            node = node->right; // Traverse to the rightmost node
        }
        cout << "Maximum value in the BST: " << node->data << endl;
    }


public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    bool isValidBST() {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    void findMinMax() {
        return findMinMax(root);
    }
};

int main() {
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
    bst.insert(20);

    if (bst.isValidBST()) {
        cout << "✅ The binary search tree is valid." << endl;
    } else {
        cout << "❌ The binary search tree is not valid." << endl;
    }
    bst.findMinMax(); // Find and print minimum and maximum values in the BST

    return 0;
}
