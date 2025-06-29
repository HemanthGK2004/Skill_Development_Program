#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int val){
        value = val;
        left = nullptr;
        right = nullptr;
    }
};
class BST{
    public:
        Node* root;
        BST(){
            root = nullptr;
        }
        Node* insert(Node* node,int val){
            if(node == nullptr){
                return new Node(val);
            }
            if(val < node->value){
                node->left = insert(node->left, val);
            } else if(val > node->value) {
                node->right = insert(node->right, val);
            }
            return node; // Return the unchanged node pointer
        }
        void insert(int val) {
        root = insert(root, val);
        } // Public insert function to start from root

        int findMin(Node* node){
            if(node == nullptr) {
                cout << "Tree is empty." << endl;
                return -1;
            }
            while(node->left != nullptr) {
                node = node->left; // Traverse to the leftmost node
            }
            return node-> value;// Print minimum value
        }
        int findMin() {
            return findMin(root); // Public function to start from root
        }
            int findMax(Node* node){
            if(node == nullptr) {
                cout << "Tree is empty." << endl;
                return -1;
            }
            while(node->right != nullptr) {
                node = node->right; // Traverse to the rightmost node
            }
            return node->value; // Print maximum value
        }
        void deleteNode(Node* node) {
            if (node == nullptr) return; // Base case: if node is null, do nothing
            deleteNode(node->left); // Recursively delete left subtree
            deleteNode(node->right); // Recursively delete right subtree
            delete node; // Delete the current node
        }
        ~BST() {
            deleteNode(root); // Destructor to clean up memory
        }
        void inorder(Node* node) {
            if (node == nullptr) return;
            inorder(node->left); // Traverse left subtree
            cout << node->value << " "; // Visit node
            inorder(node->right); // Traverse right subtree
        }
        void preorder(Node* node) {
            if (node == nullptr) return;
            cout << node->value << " "; // Visit node
            preorder(node->left); // Traverse left subtree
            preorder(node->right); // Traverse right subtree
        }
        void postorder(Node* node) {
            if (node == nullptr) return;
            postorder(node->left); // Traverse left subtree
            postorder(node->right); // Traverse right subtree
            cout << node->value << " "; // Visit node
        }
        void PrinInorder() {
            cout << "Inorder Traversal: ";
            inorder(root); // Start inorder traversal from root
            cout << endl; // Print newline after traversal
        }
        void PrinPreorder() {
            cout << "Preorder Traversal: ";
            preorder(root); // Start preorder traversal from root
            cout << endl; // Print newline after traversal
        }
        void PrinPostorder() {
            cout << "Postorder Traversal: ";
            postorder(root); // Start postorder traversal from root
            cout << endl; // Print newline after traversal
        }
    };
int main() {
    BST bst; // Create an instance of BST
    bst.insert(10); // Insert values into the BST
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    bst.PrinInorder(); // Print inorder traversal
    bst.PrinPreorder(); // Print preorder traversal
    bst.PrinPostorder(); // Print postorder traversal
    int minValue = bst.findMin(bst.root); // Find minimum value
    if (minValue != -1) {
        cout << "Minimum value in the BST: " << minValue << endl; // Print minimum value
    }
    bst.insert(20); // Insert another value into the BST
    cout << "After inserting 20:" << endl; // Confirmation message
    bst.PrinInorder(); // Print inorder traversal again
    int maxValue = bst.findMax(bst.root); // Find maximum value
    if (maxValue != -1) {
        cout << "Maximum value in the BST: " << maxValue << endl; // Print maximum value
    }
    bst.deleteNode(bst.root); // Clean up memory by deleting the BST
    cout << "BST deleted successfully." << endl; // Confirmation message

    return 0; // Return success
}