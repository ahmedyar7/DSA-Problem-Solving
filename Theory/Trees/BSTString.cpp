#include <cstring>  // For strcmp
#include <iostream>
using namespace std;

// Define a Node structure
struct Node {
  const char* data;  // Pointer to the string (const for safety)
  Node* left;        // Pointer to the left child
  Node* right;       // Pointer to the right child

  // Constructor
  Node(const char* value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a string into the binary tree
Node* insert(Node* root, const char* value) {
  if (root == nullptr) {
    // Create a new node if the tree is empty or we reach a leaf
    return new Node(value);
  }

  // Use strcmp to compare strings lexicographically
  if (strcmp(value, root->data) < 0) {
    root->left = insert(root->left, value);  // Insert into the left subtree
  } else if (strcmp(value, root->data) > 0) {
    root->right = insert(root->right, value);  // Insert into the right subtree
  }
  // Duplicate values are ignored
  return root;
}

// Function for in-order traversal (to display strings in sorted order)
void inOrderTraversal(Node* root) {
  if (root == nullptr) return;

  inOrderTraversal(root->left);   // Visit left subtree
  cout << root->data << " ";      // Visit root
  inOrderTraversal(root->right);  // Visit right subtree
}

// Function to delete the tree and free memory
void deleteTree(Node* root) {
  if (root == nullptr) return;

  deleteTree(root->left);   // Delete left subtree
  deleteTree(root->right);  // Delete right subtree
  delete root;              // Delete current node
}

int main() {
  Node* root = nullptr;

  // Array of pointers to constant strings
  const char* strings[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
  int n = sizeof(strings) / sizeof(strings[0]);

  // Build the tree
  for (int i = 0; i < n; ++i) {
    root = insert(root, strings[i]);
  }

  // Display strings in lexicographical order
  cout << "Strings in sorted order: ";
  inOrderTraversal(root);
  cout << endl;

  // Free allocated memory
  deleteTree(root);

  return 0;
}
